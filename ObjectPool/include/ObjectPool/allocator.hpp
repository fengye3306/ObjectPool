#pragma once  

namespace Object{

/**
 * @brief   策略接口
 * 
 * @tparam T 被池化的数据 的 数据类型
 */
template <typename T>
class Allocator {
public:
    /**
     * @brief 从内存池中 切取内存块 
     * 
     * @return void* 内存块
     */
    virtual void* allocator() = 0;          
    
    /**
     * @brief 向内存池归还内存块 
     * 
     * @param p 内存块
     */
    virtual void  deallocate(T *p) = 0;
}; 

}