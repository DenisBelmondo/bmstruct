#ifndef BMSTRUCT_H
#define BMSTRUCT_H

#include <stddef.h>

enum bm_numeric_type_tag {
    BM_TAG_INTEGER,
    BM_TAG_DECIMAL
};

enum bm_sign_tag {
    BM_TAG_SIGNED,
    BM_TAG_UNSIGNED
};

/* unnecessary but it might read better? */
enum bm_size_tag {
    BM_SIZE_8 = 8,
    BM_SIZE_16 = 16,
    BM_SIZE_32 = 32,
    BM_SIZE_64 = 64,
    BM_SIZE_128 = 128
};

#define BM_TAGGED_UNION_FIELDS\
    enum bm_numeric_type_tag numeric_type;\
    enum bm_sign_tag sign;\
    int size;

#define BM_TAGGED_UNION_PAYLOAD_FIELDS\
    char as_car;\
    unsigned char as_unsigned_char;\
    short as_short;\
    unsigned short as_unsigned_short;\
    int as_int;\
    unsigned int as_unsigned_int;\
    long as_long;\
    unsigned long as_unsigned_long;

struct bm_tagged_union {
    BM_TAGGED_UNION_FIELDS
    union { BM_TAGGED_UNION_PAYLOAD_FIELDS } payload;
};

struct bm_tagged_union_64 {
    BM_TAGGED_UNION_FIELDS

    union {
        BM_TAGGED_UNION_FIELDS
        long long as_long_long;
        unsigned long long as_unsigned_long_long;
    } payload;
};

#define FMT_CHAR "%c"
#define FMT_INT "%d"
#define FMT_eFLOAT "%e"
#define FMT_EFLOAT "%E"
#define FMT_FLOAT "%f"
#define FMT_GFLOAT "%G"
#define FMT_gFLOAT "%g"
#define FMT_REAL "%G"
#define FMT_real "%g"
#define FMT_SIGNED "%i"
#define FMT_LONG "%ld"
#define FMT_SLONG "%li"
#define FMT_DOUBLE "%lf"
#define FMT_LDOUBLE "%Lf"
#define FMT_LLONG "%lli"
#define FMT_ULLONG "%lld"
#define FMT_OCTAL "%o"
#define FMT_POINTER "%p"
#define FMT_PTR "%p"
#define FMT_STR "%s"
#define FMT_STRING "%s"
#define FMT_UINT "%u"
#define FMT_hex "%x"
#define FMT_HEX "%X"
#define FMT_NOTHING "%n"
#define FMT_SIZE_T "%zu"

#define BM_STATIC_ARRAY_SIZE(ARRAY) (sizeof (ARRAY) / sizeof (ARRAY[0]))
#define BM_CAST(T, EXPR) ((T)EXPR)
#define BM_CALCULATE_TOTAL_FAT_SIZE(T_HEADER, T, T_COUNT) (sizeof (T_HEADER) + (sizeof (T) * T_COUNT))

#define BM_FAT(OUT_PAYLOAD, T_HEADER, HEADER_VALUE, T, DEST) do {\
    T_HEADER header_value = HEADER_VALUE;\
    ((T_HEADER *)DEST)[0] = header_value;\
    OUT_PAYLOAD = (T *)((unsigned char *)(DEST) + sizeof (T_HEADER));\
} while (0)

#define BM_WITH(EXPR, AFTER, BODY) do { EXPR ; BODY ; AFTER ; } while (0)

#endif /* BMSTRUCT_H */
