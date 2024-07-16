# pragma once 

#include <ObjectPool/allocator.hpp>
#include <ObjectPool/ObjectPool.hpp>
#include <ObjectPool/allocator/block_allocator.hpp>

const int BlockObjectPool_Max_Size = 1;

class Class_Test_Block{
    typedef 
        Object::ObjectPool<Class_Test_Block, Object::BlockAllocator<Class_Test_Block,BlockObjectPool_Max_Size>> 
        ObjectPool;
    static ObjectPool pool;  
public:
    Class_Test_Block(int data):
        _data(data),
        _BB(-1)
    {

    };
    ~Class_Test_Block() = default;

    void *operator new(size_t n) { return pool.allocator(n);};
    void operator delete(void *p){ pool.deallocate(p);};

    int data() {return this->_data;} ;
private:
    double _data;
    double _BB;
};

Class_Test_Block::ObjectPool Class_Test_Block::pool;