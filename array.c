/* MIT License

   Copyright (c) 2025 映屿

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in all
   copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
   SOFTWARE.
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
 
typedef struct {
    int *arr_data; // 数据指针
    int size;
    int capacity;
} dynamic_arr;

dynamic_arr *
dynamic_arr_new(size_t capacity)
{
    dynamic_arr *p_da = malloc(sizeof(dynamic_arr)); // 堆分配
    if (!p_da) {
        free(p_da);
        return NULL;
    }

    p_da->size = 0;            // 当前元素个数
    p_da->capacity = capacity; // 总容量

    return p_da;
}

dynamic_arr *
dynamic_arr_add(dynamic_arr *arr, int data)
{
    if (arr->size >= arr->capacity) {
        size_t new_cap = arr->capacity * 2;
        int *new_arr = malloc(sizeof(int) * new_cap);
        if (!new_arr) {
            return NULL;
        }

        for (size_t i = 0; i < arr->size; i++) {
            new_arr[i] = arr->arr_data[i];
        }

        free(arr->arr_data);
        arr->arr_data = new_arr;
        arr->capacity = new_cap;
    }

    arr->arr_data[arr->size] = data;
    arr->size++;

    return arr;
}

int
main(int argc, char **argv)
{
    return 0;
}
