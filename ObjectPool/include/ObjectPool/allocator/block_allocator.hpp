#pragma once 

#include <ObjectPool/allocator.hpp>
#include <stdexcept>

namespace Object{


/**
 * @brief 区块策略
 * 
 * 区块策略的产生弥补了其他策略的一个麻烦————内存池大小  
 * 无论是堆策略、栈策略 本质都只是在查找速度上优化下功夫，其大小在程序启动时就被限制死而固定
 * 区块策略 我认为其本质更接近链表，因此突破了堆或栈，突破作为容器的限制，其在需要扩容时直接外挂节点 从而扩容
 * 
 * 类比一下就是ubuntu系统 我开机后可以外挂硬盘增大的我的外存空间
 * 
 * @tparam T  数据类型
 * @tparam ChunksPerBlock  每次的内存值
 */
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