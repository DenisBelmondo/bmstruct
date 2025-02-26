#ifndef BMSTRUCT_H
#define BMSTRUCT_H

#include <stddef.h>

enum bm_boolean {
    BM_FALSE,
    BM_TRUE
};

enum bm_numeric_type_tag {
    BM_TAG_INTEGER,
    BM_TAG_DECIMAL
};

enum bm_sign_tag {
    BM_TAG_SIGNED,
    BM_TAG_UNSIGNED
};

#define BM_TAGGED_UNION_FIELDS\
    unsigned char size_in_bytes;\
    unsigned char numeric_type;\
    unsigned char is_signed;\
    unsigned char is_null;\

#define BM_TAGGED_UNION_PAYLOAD_FIELDS\
    char as_char;\
    char *as_char_pointer;\
    unsigned char as_unsigned_char;\
    unsigned char *as_unsigned_char_pointer;\
    short as_short;\
    short *as_short_pointer;\
    unsigned short as_unsigned_short;\
    unsigned short *as_unsigned_short_pointer;\
    int as_int;\
    int *as_int_pointer;\
    unsigned int as_unsigned_int;\
    unsigned int *as_unsigned_int_pointer;\
    long as_long;\
    long *as_long_pointer;\
    unsigned long as_unsigned_long;\
    unsigned long *as_unsigned_long_pointer;\
    void *as_void_pointer;

struct bm_tagged_c_type {
    BM_TAGGED_UNION_FIELDS
    union { BM_TAGGED_UNION_PAYLOAD_FIELDS } payload;
};

#if defined(__STDC__) && (__STDC_VERSION__ >= 199901L)
    struct bm_tagged_64_bit_type {
        BM_TAGGED_UNION_FIELDS

        union {
            long long as_long_long;
            long long *as_long_long_pointer;
            unsigned long long as_unsigned_long_long;
            unsigned long long *as_unsigned_long_long_pointer;
        } payload;
    };
#endif

#define BM_INIT_TAGGED_INT(OUT_TAGGED_UNION, VALUE) do {\
    (OUT_TAGGED_UNION)->size_in_bytes = sizeof (int);\
    (OUT_TAGGED_UNION)->numeric_type = BM_TAG_INTEGER;\
    (OUT_TAGGED_UNION)->is_signed = BM_TRUE;\
    (OUT_TAGGED_UNION)->is_null = BM_FALSE;\
    (OUT_TAGGED_UNION)->payload.as_int = VALUE;\
} while (0)

#define BM_STATIC_ARRAY_SIZE(ARRAY) (sizeof (ARRAY) / sizeof (ARRAY[0]))
#define BM_CAST(T, EXPR) ((T)EXPR)
#define BM_CALCULATE_TOTAL_FAT_SIZE(T_HEADER, T, T_COUNT) (sizeof (T_HEADER) + (sizeof (T) * T_COUNT))

#define BM_FAT(OUT_PAYLOAD, T_HEADER, HEADER_VALUE, T, DEST) do {\
    T_HEADER header_value = HEADER_VALUE;\
    ((T_HEADER *)DEST)[0] = header_value;\
    OUT_PAYLOAD = (T *)((unsigned char *)(DEST) + sizeof (T_HEADER));\
} while (0)

#endif /* BMSTRUCT_H */
