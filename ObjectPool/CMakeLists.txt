cmake_minimum_required(VERSION 3.10)
project(ObjectPool VERSION 1.0.0 LANGUAGES CXX)

# 查找所有的头文件
file(GLOB_RECURSE header_list ./include/*.hpp)

# 添加接口库
add_library(${PROJECT_NAME} INTERFACE)

# 支持C++11标准
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_11)

target_include_directories( ${PROJECT_NAME} INTERFACE  
	${CMAKE_CURRENT_SOURCE_DIR}/include/ )	

