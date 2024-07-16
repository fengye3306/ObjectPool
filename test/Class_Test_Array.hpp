# pragma once 

#include <ObjectPool/allocator.hpp>
#include <ObjectPool/ObjectPool.hpp>
#include <ObjectPool/allocator/array_allocator.hpp>

const int ObjectPool_Max_Size = 10;

class Class_Test_Array{
    typedef 
        Object::ObjectPool<Class_Test_Array, Object::ArrayAllocator<Class_Test_Array,ObjectPool_Max_Size>> 
        ObjectPool;
    static ObjectPool pool;  
public:
    Class_Test_Array()  = default;
    ~Class_Test_Array() = default;

    void *operator new(size_t n) { return pool.allocator(n);};
    void operator delete(void *p){ pool.deallocate(p);};

};

Class_Test_Array::ObjectPool Class_Test_Array::pool;