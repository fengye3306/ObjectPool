# ObjectPool

## 简介

`ObjectPool` 是一个简单高效的对象池实现，用于管理对象的分配和释放。
它利用块分配器 (`BlockAllocator`) 来优化内存管理，减少频繁的内存分配和释放操作对性能的影响。

* 支持自定义对象分配器
* 基于块的内存分配，提高内存使用效率
* 简单易用的接口，适用于各种类型的对象

## 构建和安装

> 安装需求

- CMake 版本 >= 3.10
- GCC 编译器，支持 C++11 标准

> BUILD

1. 克隆项目到本地

   ```bash
   git clone https://github.com/yourusername/ObjectPool.git
   cd ObjectPool


2. 创建构建目录并使用 CMake 生成构建文件  

```bash
mkdir build
cd build
cmake ..
```

3. 编译项目

```bash
make
```

> INSTALL

```bash
make install
```