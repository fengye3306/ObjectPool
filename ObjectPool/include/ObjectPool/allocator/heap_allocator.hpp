#pragma once 

#include <ObjectPool/allocator.hpp>
#include <stdexcept>
#include <algorithm>

namespace Object{

template <typename T, int N> 
class HeapAllocator : public Allocator<T> {


    enum State{
        FREE = 1,
        USED = 0
    };

    struct Entry{
    public:
        HeapAllocator::State state;
        T *p;        
        bool operator < (const Entry &other) const {
            return state < other.state;
        }   
    }; 



public:
    HeapAllocator()
    {
        m_available = N;
        for(int i = 0 ; i<N; i++){
            m_entry[i].state = State::FREE;
            m_entry[i].p     = 
                reinterpret_cast<T *>(&m_data[sizeof(T) * i]);
        }
        // 生成大堆
        std::make_heap(m_entry, m_entry + N);
    };
    ~HeapAllocator() = default;


    virtual void* allocator() override{
        if(this->m_available <= 0){
            throw std::bad_alloc();
        }
        Entry e = m_entry[0];
        std::pop_heap(m_entry, m_entry + N);
        m_available--;
        
        m_entry[m_available].state = State::USED;
        m_entry[m_available].p = nullptr;

        return e.p;
    }         
    virtual void  deallocate(T *p) override{
        if( p == nullptr || m_available >= N){
            return;
        }
        m_entry[m_available].state = State::FREE;
        m_entry[m_available].p = reinterpret_cast<T *>(p);

        m_available++;

        std::make_heap(m_entry, m_entry + N);
    }

private:
    unsigned char m_data[sizeof(T) * N];
    Entry m_entry[N];
    int m_available;
};

}