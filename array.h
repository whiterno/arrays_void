#ifndef _MAIN
#define _MAIN
struct Array{
    void* data;
    size_t length;
    size_t array_elem_size;
};

typedef void (*myPrinter_t)(void* elem);

void arrayCtor(Array* arr, size_t length, size_t array_elem_size);
void* arrayGetItem(Array* arr, size_t index);
void arrayCopy(Array* dest, const Array* src);
void arrayOutput(Array* arr, myPrinter_t printer);
void arrayDtor(Array* arr);

#endif
