#pragma once 

#include <ObjectPool/allocator.hpp>
#include <stdexcept>

namespace Object{
template <typename T, int ChunksPerBlock> 
class BlockAllocator : public Allocator<T>{

    struct Chunk {
        Chunk *next;
    };

public:
    BlockAllocator() :_head(nullptr){

    };
    ~BlockAllocator() = default;

    virtual void* allocator() override{
        if(_head == nullptr )
        {   
            if(sizeof( T ) < sizeof(T *) ){
                std::cerr << "Object size less than pointer size" << std::endl;
                throw std::bad_alloc();
            }
            _head = allocator_block(sizeof(T));  
        }
        Chunk *p = _head;
        _head = _head->next;    
        return reinterpret_cast<T *>(p);
    };             
    virtual void  deallocate(T *p) override{
        auto chunk = reinterpret_cast<Chunk *>(p);
        chunk->next = _head;
        _head = chunk; 
    };

private:

    Chunk* allocator_block(size_t chunk_size){
        size_t block_size = chunk_size *ChunksPerBlock;

        auto head  = reinterpret_cast<Chunk*> (::malloc(block_size));
        auto chunk = head;

        for(int i = 0; i < ChunksPerBlock -1; i++){
            chunk->next = reinterpret_cast<Chunk*>(reinterpret_cast<unsigned char*>(chunk)+ chunk_size);
            chunk = chunk->next;
        }
        chunk->next = nullptr;
        return head;
    }

private:
    Chunk *_head;
};


}