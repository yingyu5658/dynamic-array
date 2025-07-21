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
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int32_t *data; // 数据指针
    size_t size;
    size_t capacity;
} dynamic_arr;

dynamic_arr *
dynamic_arr_new(size_t capacity) {
    dynamic_arr *p_da = malloc(sizeof(dynamic_arr));
    if (!p_da) {
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }

    p_da->data = malloc(sizeof(int32_t) * capacity);
    if (!p_da->data) {
        free(p_da);
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }

    p_da->size = 0;            // 当前元素个数
    p_da->capacity = capacity; // 总容量
    return p_da;
}

void
dynamic_arr_add(dynamic_arr *arr, int32_t data) {
    if (arr->size >= arr->capacity) {
        int32_t *temp = realloc(arr->data, arr->capacity * 2 * sizeof(int32_t));
        if (!temp) {
            fprintf(stderr, "Memory allocation failed.\n");
            exit(1);
        }

        arr->data = temp;
        arr->capacity *= 2;
    }

    arr->data[arr->size] = data;
    arr->size++;
}

// Example:
// my_dynamic_arr = dynamic_arr_del(my_dynamic_arr)
void
dynamic_arr_del(dynamic_arr *arr) {
    if (arr == NULL) {
        return;
    }

    free(arr->data);
    free(arr);
}

int32_t
dynamic_arr_get_item(dynamic_arr *arr, size_t index, int32_t *out_value) {
    if (!arr) {
        fprintf(stderr, "dynamic_arr was NULL.\n");
        return -1;
    }
    if (index >= arr->size) {
        fprintf(stderr, "'index' was bigger than arr->size.\n");
        return -2;
    }

    *out_value = arr->data[index];
    return 0;
}

int32_t
dynamic_arr_modify_item(dynamic_arr *arr, size_t index, int32_t data) {
    if (!arr) {
        fprintf(stderr, "dynamic_arr was NULL.\n");
        return -1;
    }

    if (index >= arr->size) {
        fprintf(stderr, "index was bigger than arr->size.");
        return -2;
    }

    arr->data[index] = data;
    return 0;
}
