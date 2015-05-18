#ifndef CLASSLOADER_H
#define CLASSLOADER_H

#include <stdint.h>

class AshFile;

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;

using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;

enum AccessFlag {
    ACC_PUBLIC = 1,
    ACC_PRIVATE = 2,
    ACC_PROTECTED = 4,
    ACC_STATIC = 8,
    ACC_FINAL = 16,
    ACC_VOLATILE = 64,
    ACC_TRANSIENT = 128,
    ACC_SYNTHETIC = 4096,
    ACC_ENUM = 16384
};

struct constant_entry {
    u8 tag;
};

struct constant_class : constant_entry {
    u16 name_index;
};

struct constant_field : constant_entry {
    u16 class_index;
    u16 name_and_type_index;
};

struct constant_method : constant_field {
    /* data */
};

struct constant_interface_method : constant_method {
    /* data */
};

struct constant_string : constant_entry {
    u16 string_index;
};

struct constant_integer : constant_entry {
    i32 bytes;
};

struct constant_float : constant_entry {
    float bytes;
};

struct constant_long : constant_entry {
    u32 high_bytes;
    u32 low_bytes;
};

struct constant_double : constant_long {

};

struct constant_name_and_type : constant_entry {
    u16 name_index;
    u16 descriptor_index;
};

struct constant_utf8 : constant_entry {
    u16 length;
    u8* bytes;
};

struct constant_method_handle : constant_entry {
    u8 reference_kind;
    u16 reference_index;
};

struct constant_method_type : constant_entry {
    u16 descriptor_index;
};

struct constant_invoke_dyamic : constant_entry {
    u16 bootstrap_method_attr_index;
    u16 name_and_type_index;
};

struct attribute_entry {
    u16 attribute_name_index;
    u32 attribute_length;
    u8* data;
};

struct field_entry {
    u16 access_flags;
    u16 name_index;
    u16 descriptor_index;
    u16 attribute_count;
    attribute_entry** attributes;
};

struct method_entry {
    u16 access_flags;
    u16 name_index;
    u16 descriptor_index;
    u16 attribute_count;
    attribute_entry** attributes;
};

struct ClassFile {
    u32 magic;
    u16 minor, major;
    u16 constant_pool_count;
    constant_entry** constant_pool;
    u16 access_flags;
    u16 this_class;
    u16 super_class;
    u16 interface_count;
    u16* interfaces;
    u16 field_count;
    field_entry** fields;
    u16 method_count;
    method_entry** methods;
    u16 attribute_count;
     attribute_entry** attributes;
};

namespace ClassLoader {
    u8 read8();
    u16 read16();
    u32 read32();
    void readVersion();
    void readMagic();
    constant_entry* readConstantEntry(int offset);
    void readConstantPool();
    attribute_entry* readAttribute();
    field_entry* readField();
    void readFields();
    method_entry* readMethod();
    void readMethods();
    void readAttributes();
    ClassFile* loadClass(AshFile* file);
} /* ClassLoader */


#endif /* end of include guard: CLASSLOADER_H */
