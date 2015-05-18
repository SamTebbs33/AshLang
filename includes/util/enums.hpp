#ifndef ENUMS_H
#define ENUMS_H

struct EnumVarDecKeyword{
	enum type{
		CONST, VAR
	};
};

struct EnumModifier{
	enum type{
		PUBLIC=1, PRIVATE=2, PROTECTED=4, FINAL=8, REQUIRED=16, NATIVE=32, OVERRIDE=64, STANDARD=128, STATIC=256, ABSTRACT=512, INVALID=1024
	};
};

struct EnumType{
    enum type{
        CLASS,
        PROTOCOL,
        ENUM,
		NUM_TYPES
    };
};

#endif /* end of include guard: ENUMS_H */
