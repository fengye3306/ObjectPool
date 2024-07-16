#include <iostream>

#include <ObjectPool/allocator.hpp>
#include <ObjectPool/ObjectPool.hpp>
#include <ObjectPool/allocator/array_allocator.hpp>
#include "Class_Test_Heap.hpp"

int main() {

    Class_Test_Heap *arr[10] = { nullptr };

    // Create objects
    for (int i = 0; i < 10; ++i) {
        arr[i] = new Class_Test_Heap();
    }

    // Delete objects (use delete[])
    for (int i = 0; i < 10; ++i) {
        delete arr[i];
    }

    // Create objects
    for (int i = 0; i < 10; ++i) {
        arr[i] = new Class_Test_Heap();
    }

    // Delete objects (use delete[])
    for (int i = 0; i < 10; ++i) {
        delete arr[i];
    }
    Class_Test_Heap *sin  = new Class_Test_Heap();
}


