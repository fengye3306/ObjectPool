
# pragma once 

#include <ObjectPool/allocator.hpp>
#include <stdexcept>

namespace Object{

template <typename T,typename Allocator>
class ObjectPool {
public:
    ObjectPool()  = default;
    ~ObjectPool() = default;

    void* allocator(size_t n){
        if(sizeof(T) != n){
            throw std::bad_alloc();
        }
        return m_allocator.allocator();
    };

    void deallocate(void *p){
        m_allocator.deallocate(static_cast<T *>(p));
    }
private:
    Allocator m_allocator;                      
};

}