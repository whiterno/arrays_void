#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <cstring>
#include "array.h"

void arrayCtor(Array* arr, size_t length, size_t array_elem_size){
    assert(arr);

    arr->data = (void*)calloc(length, array_elem_size);
    arr->length = length;
    arr->array_elem_size = array_elem_size;
}


void* arrayGetItem(Array* arr, size_t index){
    assert(arr);

    return (char*)arr->data + index * arr->array_elem_size;
}

void arrayCopy(Array* dest, const Array* src){
    memcpy(dest, src, sizeof(Array));
}

void arrayOutput(Array* arr, myPrinter_t printer){
    for (size_t elem = 0; elem < arr->length; elem++){
        printer((char*)arr->data + elem * arr->array_elem_size);
    }
}

void arrayDtor(Array* arr){
    assert(arr);

    free(arr->data);

    arr->data = NULL;
    arr->length = 0;
    arr->array_elem_size = 0;
}
