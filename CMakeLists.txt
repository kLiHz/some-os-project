project(Project)
cmake_minimum_required(VERSION 3.1)

add_subdirectory(thread)

add_executable(MyThreadDemo "MyThreadDemo.cpp")
target_link_libraries(MyThreadDemo MyThread)

add_executable(ProducerProcess "ProducerProcess.cpp")
target_link_libraries(ProducerProcess MyThread)
