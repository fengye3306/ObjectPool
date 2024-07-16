#include <iostream>

#include <ObjectPool/allocator.hpp>
#include <ObjectPool/ObjectPool.hpp>
#include <ObjectPool/allocator/array_allocator.hpp>

#include "Class_Test_Block.hpp"

int main() {


    // Create objects
    for (int i = 0; i < 10000; ++i) {
        Class_Test_Block *block_ = new Class_Test_Block(i);
        std::cout << block_->data() << std::endl;
    };
}


