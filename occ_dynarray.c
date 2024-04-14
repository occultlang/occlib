#include "occ_dynarray.h"

dyn_array* create_array_long() {
    dyn_array* array = (dyn_array*)tgc_alloc(&gc, sizeof(dyn_array));

    if (array == (void*)0) {
        exit(1);
    }

    array->size = 0;
    array->num = (long*)tgc_alloc(&gc, sizeof(long));

    if (array->num == (void*)0) {
        tgc_free(&gc, array);
        exit(1);
    }

    return array;
}

dyn_array* create_array_double() {
    dyn_array* array = (dyn_array*)tgc_alloc(&gc, sizeof(dyn_array));

    if (array == (void*)0) {
        exit(1);
    }

    array->size = 0;
    array->rnum = (double*)tgc_alloc(&gc, sizeof(double));

    if (array->rnum == (void*)0) {
        tgc_free(&gc, array);
        exit(1);
    }

    return array;
}

dyn_array* create_array_string() {
    dyn_array* array = (dyn_array*)tgc_alloc(&gc,sizeof(dyn_array));

    if (array == (void*)0) {
        exit(1);
    }

    array->size = 0;
    array->str = (char**)tgc_alloc(&gc, sizeof(char*));

    if (array->str == (void*)0) {
        tgc_free(&gc, array);
        exit(1);
    }

    return array;
}

dyn_array* create_array_self() {
    dyn_array* array = (dyn_array*)tgc_alloc(&gc,sizeof(dyn_array));

    if (array == (void*)0) {
        exit(1);
    }

    array->size = 0;
    array->self = (dyn_array**)tgc_alloc(&gc, sizeof(dyn_array*));

    if (array->self == (void*)0) {
        tgc_free(&gc, array);
        exit(1);
    }

    return array;
}

int get_size(dyn_array* array) {
    return array->size;
}

long get_num(dyn_array* array, int index) {
    if (index < 0 || index >= array->size) {
        exit(1);
    }

    return array->num[index];
}

void add_num(dyn_array* array, long data) {
    if (array->num == (void*)0) {
        exit(1);
    }

    array->size++;
    array->num = (long*)tgc_realloc(&gc, array->num, array->size * sizeof(long));

    if (array->num == (void*)0) {
        exit(1);
    }

    array->num[array->size - 1] = data;
}

void set_num(dyn_array* array, int index, long data) {
    if (index < 0 || index >= array->size) {
        exit(1);
    }

    array->num[index] = data;
}

void set_self(dyn_array* array, int index, dyn_array* data) {
    if (index < 0 || index >= array->size) {
        exit(1);
    }

    array->self[index] = data;
}

double get_rnum(dyn_array* array, int index) {
    if (index < 0 || index >= array->size) {
        exit(1);
    }

    return array->rnum[index];
}

dyn_array* get_self(dyn_array* array, int index) {
    if (index < 0 || index >= array->size) {
        exit(1);
    }

    return array->self[index];
}

void add_rnum(dyn_array* array, double data) {
    if (array->rnum == (void*)0) {
        exit(1);
    }

    array->size++;
    array->rnum = (double*)tgc_realloc(&gc, array->rnum, array->size * sizeof(double));

    if (array->rnum == (void*)0) {
        exit(1);
    }

    array->rnum[array->size - 1] = data;
}

void set_rnum(dyn_array* array, int index, double data) {
    if (index < 0 || index >= array->size) {
        exit(1);
    }

    array->rnum[index] = data;
}

char* get_str(dyn_array* array, int index) {
    if (index < 0 || index >= array->size) {
        exit(1);
    }

    return array->str[index];
}

void add_str(dyn_array* array, char* data) {
    if (array->str == (void*)0) {
        exit(1);
    }

    array->size++;
    array->str = (char**)tgc_realloc(&gc, array->str, array->size * sizeof(char*));

    if (array->str == (void*)0) {
        exit(1);
    }

    array->str[array->size - 1] = data;
}

void set_str(dyn_array* array, int index, char* data) {
    if (index < 0 || index >= array->size) {
        exit(1);
    }

    array->str[index] = data;
}

void add_self(dyn_array* array, dyn_array* data) {
    if (array->self == (void*)0) {
        exit(1);
    }

    array->size++;
    array->self = (dyn_array**)tgc_realloc(&gc, array->self, array->size * sizeof(dyn_array*));

    if (array->self == (void*)0) {
        exit(1);
    }

    array->self[array->size - 1] = data;
}