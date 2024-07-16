#pragma once 

#include <ObjectPool/allocator.hpp>
#include <stdexcept>

namespace Object{
template <typename T, int N> 
class ArrayAllocator : public Allocator<T>{

public:
    ArrayAllocator() {
        for(int i = 0; i < N;  i++){
            m_used[i] = false;
        }
    };
    ~ArrayAllocator() = default;

    virtual void* allocator() override{
        for(int i = 0; i < N; i++){
            if( false == m_used[i]){
                m_used[i] = true;
                return reinterpret_cast<T *> (&m_data[sizeof(T) * i]);
            }      
        }
        throw std::bad_alloc(); 
    };             
    virtual void  deallocate(T *p) override{
        auto i = ((unsigned char *) p -m_data) /sizeof(T);
        m_used[i] = false;
    };

private:
    unsigned char m_data[sizeof(T) * N]; 
    bool          m_used[N];
};


}