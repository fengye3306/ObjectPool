#pragma once 

namespace Object{

template <typename T>
class Allocator {
public:
    virtual void* allocator() = 0;
    virtual void  deallocate(T *p) = 0;
};

}