cmake_minimum_required( VERSION 3.10 )
project( ObjectPool CXX ) 

file( GLOB_RECURSE header_list ./include/*.h )			# 所有.h文件
file( GLOB 		   source_list ./src/*.cpp )			# 所有.cpp文件

add_library(${PROJECT_NAME} SHARED
    ${header_list}
    ${source_list}
)

# 引入自己的头文件目录路径  公有化使得当此库被包含时共享此环境
target_include_directories( ${PROJECT_NAME} PUBLIC  
	${CMAKE_CURRENT_SOURCE_DIR}/include/ )	

# 引入构建目录路径
target_include_directories( ${PROJECT_NAME} PUBLIC  
	 ${CMAKE_CURRENT_BINARY_DIR} )	

# 支持c++11标准
target_compile_features(
	${PROJECT_NAME} PRIVATE cxx_std_11
)


