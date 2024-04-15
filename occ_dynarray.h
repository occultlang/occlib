#ifndef OCC_DYNARRAY_H
#define OCC_DYNARRAY_H

#include "tgc.h"

static tgc_t gc;

typedef struct dyn_array {
    union { // data types
        long* num;
        double* rnum;
        char** str;
        struct dyn_array** self;
    };
    
    int size;
} dyn_array;

dyn_array* create_array_long();
dyn_array* create_array_double();
dyn_array* create_array_string();
dyn_array* create_array_self();
int get_size(dyn_array* array);
long get_num(dyn_array* array, int index);
void add_num(dyn_array* array, long data);
void set_num(dyn_array* array, int index, long data);
void set_self(dyn_array* array, int index, dyn_array* data);
double get_rnum(dyn_array* array, int index);
dyn_array* get_self(dyn_array* array, int index);
void add_rnum(dyn_array* array, double data);
void set_rnum(dyn_array* array, int index, double data);
char* get_str(dyn_array* array, int index);
void add_str(dyn_array* array, char* data);
void set_str(dyn_array* array, int index, char* data);
void add_self(dyn_array* array, dyn_array* data);

#define DYN_VECTOR_PUSH_BACK(vec, data) _Generic((data), \
    int: add_num, \
    long: add_num, \
    char*: add_str, \
    float: add_rnum, \
    double: add_rnum, \
    default: add_self \
)(vec, data)

#define DYN_VECTOR_AT(vec, index, cast_type) _Generic((cast_type), \
    int: get_num, \
    long: get_num, \
    char*: get_str, \
    float: get_rnum, \
    double: get_rnum, \
    default: get_self \
)(vec, index)

#define CAST_TYPE_NUM 0
#define CAST_TYPE_REALNUM 0.1
#define CAST_TYPE_STRING "0ab1a"
#define CAST_TYPE_SELF // TODO

#define DYN_VECTOR_SIZE(vec) ((vec)->size)

#endif /* OCC_DYNARRAY_H */
