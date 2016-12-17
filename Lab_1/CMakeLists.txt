cmake_minimum_required(VERSION 3.6)
project(Lab_1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES read_write_lock_implementation.cpp LinkedList.h support_functions.h MyThreadClass.h)

add_executable(Lab_1 ${SOURCE_FILES})

target_link_libraries(Lab_1 pthread)