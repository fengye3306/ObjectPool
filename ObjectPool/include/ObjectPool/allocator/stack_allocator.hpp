#pragma once 

#include <ObjectPool/allocator.hpp>
#include <stdexcept>
#include <algorithm>

namespace Object{

template <typename T, int N> 
class StackAllocator : public Allocator<T> {

public:
    StackAllocator()
    {
        m_allocated = 0;
        m_available = 0;
    };
    ~StackAllocator() = default;

    virtual void* allocator() override{
        if(m_available <= 0 && m_allocated >= N){
            throw std::bad_alloc();
        }
        if(m_available > 0){
            return m_stack[--m_available];
        }
        else {
            auto p = m_data + sizeof(T) * m_allocated;
            m_allocated++;
            return reinterpret_cast<T *>(p);
        }
    }         
    virtual void  deallocate(T *p) override{
        m_stack[m_available++] = p;
    }
private:
    unsigned char m_data[sizeof(T) * N];
    std::array<T *,N> m_stack;
    int m_allocated;
    int m_available;
};

}