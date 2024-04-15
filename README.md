# occlib
The occult C backend, using tgc as a garbage collector.

# How to use

## Dynamic arrays
```c++
#include <stdio.h>
#include "occ_dynarray.h"

int main(int argc, char *argv[]) {
    tgc_start(&gc, argv);

    dyn_array* vec = create_array_string();

    DYN_VECTOR_PUSH_BACK(vec, "Hi World!");

    char* a = DYN_VECTOR_AT(vec, 0, a);

    printf("%s\n", a);

    tgc_stop(&gc);

    return 0;
}
```
