cmake_minimum_required( VERSION 3.10 )
project( test CXX ) 

file( GLOB test_header_list ./*.h )			# 所有.h文件
file( GLOB test_source_list ./*.cpp )		# 所有.cpp文件

add_executable(
	${PROJECT_NAME} 
    ${test_header_list}
    ${test_source_list}
)

target_link_libraries(${PROJECT_NAME} ObjectPool)