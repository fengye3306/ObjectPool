cmake_minimum_required(VERSION 3.10)

# 添加ObjectPool子目录
add_subdirectory(./ObjectPool)

option(ENABLE_TESTS "Enable test compilation" OFF)
# 根据选项决定是否添加test子目录
if(ENABLE_TESTS)
    add_subdirectory(./test)
endif()

