#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <cstring>
#include "array.h"

int scanTornMatrix(Array* arr);
void printTornMatrix(Array arr);
void tornMatrixPrinter(void* arr);
void intPrinter(void* arr);

const size_t SIZE = 5;

int main(void){
    Array arr;
    arrayCtor(&arr, 0, sizeof(Array));

    scanTornMatrix(&arr);
    printTornMatrix(arr);

    arrayOutput(&arr, &tornMatrixPrinter);
}

int scanTornMatrix(Array* arr){
    printf("Введите количество строк матрицы: \n");
    scanf("%lu", &arr->length);

    arrayCtor(arr, arr->length, arr->array_elem_size);
    printf("Введите %lu чисел, равных длине строки: \n", arr->length);
    for (size_t i = 0; i < arr->length; i++){
        scanf("%lu", &((Array*)arrayGetItem(arr, i))->length);
    }

    printf("Введите числа: \n");
    for (size_t y = 0; y < arr->length; y++){
        Array* minor = (Array*)arrayGetItem(arr, y);
        arrayCtor(minor, ((Array*)arrayGetItem(arr, y))->length, sizeof(int));
        for (size_t x = 0; x < minor->length; x++){
            scanf("%d", (int*)minor->data + x);
        }
    }
    return 0;
}

void printTornMatrix(Array arr){
    for (size_t y = 0; y < arr.length; y++){
        Array* minor = (Array*)arrayGetItem(&arr, y);
        for (size_t x = 0; x < minor->length; x++){
            printf("%d ", *(int*)arrayGetItem(minor, x));
        }
        printf("\n");
    }
}

void tornMatrixPrinter(void* arr){
    Array* arr_tmp = (Array*)arr;

    printf("length = %lu, data_pointer = %p : ", arr_tmp->length, arr_tmp->data);
    for (size_t i = 0; i < arr_tmp->length; i++){
        intPrinter((char*)arr_tmp->data + i * arr_tmp->array_elem_size);
    }
    printf("\n");
}

void intPrinter(void* el){
    int* el_tmp = (int*)el;

    printf("%d ", *el_tmp);
}
