#include <fstream>
#include <stdio.h>
#include <loader/classloader.hpp>
#include <loader/classimporter.hpp>

// Source: https://docs.oracle.com/javase/specs/jvms/se7/html/jvms-4.html

char* buffer;
int idx = 0;
size_t len = 0;

ClassFile* classFile;

u8 ClassLoader::read8(){
    if(idx + 1 <= len) return buffer[idx++];
    printf("Overrun buffer: %d:%d\n", idx, len);
    exit(0);
    return 0;
}

u16 ClassLoader::read16(){
    return read8() << 8 | read8();
}

u32 ClassLoader::read32(){
    return read16() << 16 | read16();
}

void ClassLoader::readMagic(){
    classFile->magic = read32();
}

void ClassLoader::readVersion(){
    classFile->minor = read16();
    classFile->major = read16();
}

constant_entry* ClassLoader::readConstantEntry(int offset){
    u8 tag = read8();
    switch(tag){
        case 7: { // CLASS_info
            constant_class* entry = new constant_class();
            entry->tag = tag;
            entry->name_index = read16();
            printf("Read class info (name_index:offset): %d:%d\n", entry->name_index, offset);
            return entry;
            }
        case 9: {// FIELD_info
            constant_field* entry = new constant_field();
            entry->tag = tag;
            entry->class_index = read16();
            entry->name_and_type_index = read16();
            return entry;
            }
        case 10:{ // METHOD_info
            constant_method* entry = new constant_method();
            entry->tag = tag;
            entry->class_index = read16();
            entry->name_and_type_index = read16();
            return entry;
        }
        case 11:{ // INTERFACE_METHOD_info
            constant_interface_method* entry = new constant_interface_method();
            entry->tag = tag;
            entry->class_index = read16();
            entry->name_and_type_index = read16();
            return entry;
        }
        case 8:{ // STRING
            constant_string* entry = new constant_string();
            entry->tag = tag;
            entry->string_index = read16();
            return entry;
        }
        case 3:{ // INTEGER
            constant_integer* entry = new constant_integer();
            entry->tag = tag;
            entry->bytes = (int) read32();
            return entry;
        }
        case 4:{ // FLOAT
            constant_float* entry = new constant_float();
            entry->tag = tag;
            u32 iVal = read32();
            entry->bytes = reinterpret_cast<float&>(iVal);
            return entry;
        }
        case 5:{ // LONG
            constant_long* entry = new constant_long();
            entry->tag = tag;
            entry->high_bytes = read32();
            entry->low_bytes = read32();
            return entry;
        }
        case 6:{ // DOUBLE
            constant_double* entry = new constant_double();
            entry->tag = tag;
            entry->high_bytes = read32();
            entry->low_bytes = read32();
            return entry;
        }
        case 12:{ // NAME_AND_TYPE
            constant_name_and_type* entry = new constant_name_and_type();
            entry->tag = tag;
            entry->name_index = read16();
            entry->descriptor_index = read16();
            return entry;
        }
        case 1:{ // UTF8_STRING
            constant_utf8* entry = new constant_utf8();
            entry->tag = tag;
            entry->length = read16();
            entry->bytes = new u8[entry->length];
            for(int i = 0; i < entry->length; i++) entry->bytes[i] = read8();
            printf("Read String:%d: ", offset);
            for(int i = 0; i < entry->length; i++){
                printf("%c", (char)entry->bytes[i]);
            }
            printf("\n");
            return entry;
        }
        case 15:{ // METHOD_HANDLE
            constant_method_handle* entry = new constant_method_handle();
            entry->tag = tag;
            entry->reference_kind = read8();
            entry->reference_index = read16();
            return entry;
        }
        case 16:{ // METHOD_TYPE
            constant_method_type* entry = new constant_method_type();
            entry->tag = tag;
            entry->descriptor_index = read16();
            return entry;
        }
        case 18:{ // INVOKE_DYNAMIC
            constant_invoke_dyamic* entry = new constant_invoke_dyamic();
            entry->tag = tag;
            entry->bootstrap_method_attr_index = read16();
            entry->name_and_type_index = read16();
            return entry;
        }
    }
    return NULL;
}

void ClassLoader::readConstantPool(){
    classFile->constant_pool_count = read16()-1;
    classFile->constant_pool = new constant_entry*[classFile->constant_pool_count];
    for (size_t c = 0; c < classFile->constant_pool_count; c++) {
        classFile->constant_pool[c] = readConstantEntry(c);
    }
}

attribute_entry* ClassLoader::readAttribute(){
    attribute_entry* entry = new attribute_entry();
    entry->attribute_name_index = read16();
    entry->attribute_length = read32();
    entry->data = new u8[entry->attribute_length];
    for(int i = 0; i < entry->attribute_length; i++) entry->data[i] = read8();
    return entry;
}

field_entry* ClassLoader::readField(){
    field_entry* entry = new field_entry();
    entry->access_flags = read16();
    entry->name_index = read16();
    entry->descriptor_index = read16();
    entry->attribute_count = read16();
    entry->attributes = new attribute_entry*[entry->attribute_count];
    for(int i = 0; i < entry->attribute_count; i++) entry->attributes[i] = readAttribute();
}

void ClassLoader::readFields(){
    classFile->field_count = read16();
    classFile->fields = new field_entry*[classFile->field_count];
    for(int i = 0; i < classFile->field_count; i++) classFile->fields[i] = readField();
}

method_entry* ClassLoader::readMethod(){
    method_entry* entry = new method_entry();
    entry->access_flags = read16();
    entry->name_index = read16();
    entry->descriptor_index = read16();
    entry->attribute_count = read16();
    entry->attributes = new attribute_entry*[entry->attribute_count];
    for(int i = 0; i < entry->attribute_count; i++) entry->attributes[i] = readAttribute();
}

void ClassLoader::readMethods(){
    classFile->method_count = read16();
    classFile->methods = new method_entry*[classFile->method_count];
    for(int i = 0; i < classFile->method_count; i++) classFile->methods[i] = readMethod();
}

void ClassLoader::readAttributes(){
    classFile->attribute_count = read16();
    classFile->attributes = new attribute_entry*[classFile->attribute_count];
    for(int i = 0; i < classFile->attribute_count; i++) classFile->attributes[i] = readAttribute();
}

ClassFile* ClassLoader::loadClass(AshFile* file){
    classFile = new ClassFile();
    file->stream->seekg(0, std::ios::end);
    len = file->stream->tellg();
    file->stream->seekg(0, std::ios::beg);
    buffer = new char[len];
    file->stream->read(buffer, len);
    file->stream->close();
    delete file->stream;

    readMagic();
    readVersion();
    readConstantPool();
    classFile->access_flags = read16();
    classFile->this_class = read16();
    classFile->super_class = read16();
    classFile->interface_count = read16();
    classFile->interfaces = new u16[classFile->interface_count];
    for(int i = 0; i < classFile->interface_count; i++) classFile->interfaces[i] = read16();
    readFields();
    readMethods();
    readAttributes();
    return classFile;
}
