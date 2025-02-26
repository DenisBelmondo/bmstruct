#include <stdio.h>
#include "bmstruct.h"

/* test lhs expansion */
#define STATIC_ARRAY_SIZE(ARRAY) BM_STATIC_ARRAY_SIZE(ARRAY)

int main(void) {
    struct bm_tagged_c_type asdf;

    BM_INIT_TAGGED_INT(&asdf, 1234);
    printf(FMT_INT "\n", asdf.payload.as_int);

    return 0;
}
