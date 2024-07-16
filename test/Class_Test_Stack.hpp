# pragma once 

#include <ObjectPool/allocator.hpp>
#include <ObjectPool/ObjectPool.hpp>
#include <ObjectPool/allocator/stack_allocator.hpp>

const int ObjectPool_Max_Size = 1;

class Class_Test_Stack{
    typedef 
        Object::ObjectPool<Class_Test_Stack, Object::StackAllocator<Class_Test_Stack,ObjectPool_Max_Size>> 
        ObjectPool;
    static ObjectPool pool;  
public:
    Class_Test_Stack()  = default;
    ~Class_Test_Stack() = default;

    void *operator new(size_t n) { return pool.allocator(n);};
    void operator delete(void *p){ pool.deallocate(p);};

};

Class_Test_Stack::ObjectPool Class_Test_Stack::pool;