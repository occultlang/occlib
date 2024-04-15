# occlib
The occult C backend, using tgc as a garbage collector.

# How to use

## Dynamic arrays
```c
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

Basic multidimensional array of

```c
int array[2][2] = { {1, 2},
                    {3, 4} };
```

```c
int main(int argc, char *argv[]) {
    tgc_start(&gc, argv);

    dyn_array* array = create_array_self();
    printf("Created new self\n");
    
    DYN_VECTOR_PUSH_BACK(array, create_array_long());
    DYN_VECTOR_PUSH_BACK(array, create_array_long());

    printf("Created new array(s)\n");

    dyn_array* row_array = DYN_VECTOR_AT(array, 0, row_array);
    DYN_VECTOR_PUSH_BACK(row_array, 1);
    DYN_VECTOR_PUSH_BACK(row_array, 2);
    printf("Added content to (1)\n");

    dyn_array* row_array2 = DYN_VECTOR_AT(array, 1, row_array2);
    DYN_VECTOR_PUSH_BACK(row_array2, 3);
    DYN_VECTOR_PUSH_BACK(row_array2, 4);
    printf("Added content to (2)\n");

    for (int row = 0; row < DYN_VECTOR_SIZE(array); row++) {
        dyn_array* row_array = DYN_VECTOR_AT(array, row, row_array);
        for (int col = 0; col < DYN_VECTOR_SIZE(row_array); col++) {
            printf("%ld ", DYN_VECTOR_AT(row_array, col, CAST_TYPE_NUM));
        }
        printf("\n");
    }

    tgc_stop(&gc);

    return 0;
}
```
