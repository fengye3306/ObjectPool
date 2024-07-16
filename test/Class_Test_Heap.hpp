# pragma once 

#include <ObjectPool/allocator.hpp>
#include <ObjectPool/ObjectPool.hpp>
#include <ObjectPool/allocator/heap_allocator.hpp>

const int ObjectPool_Max_Size = 10;

class Class_Test_Heap{
    typedef 
        Object::ObjectPool<Class_Test_Heap, Object::HeapAllocator<Class_Test_Heap,ObjectPool_Max_Size>> 
        ObjectPool;
    static ObjectPool pool;  
public:
    Class_Test_Heap()  = default;
    ~Class_Test_Heap() = default;

    void *operator new(size_t n) { return pool.allocator(n);};
    void operator delete(void *p){ pool.deallocate(p);};

};

Class_Test_Heap::ObjectPool Class_Test_Heap::pool;