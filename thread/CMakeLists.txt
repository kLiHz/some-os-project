project(MyThread)
cmake_minimum_required(VERSION 3.1)

find_package(Threads REQUIRED)

add_library(MyThread INTERFACE)
target_include_directories(MyThread INTERFACE .)
target_link_libraries(MyThread INTERFACE Threads::Threads)
