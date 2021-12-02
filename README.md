# Project

## Thread class

[`MyThread`](./thread/) class is a Java-like wrapper of `pthread` calls.

How to use: Simply include `MyThread.h` into C++ source files. Build with option `-lpthread`.

Assume that `MyThread.h` is in the directory `thread`, you can build the simple demo with following commands.

```console
$ g++ -I ./thread MyThreadDemo.cpp -o ./MyThreadDemo.out -lpthread
$ ./MyThreadDemo.out
```

Or you can use CMake:

```cmake
# Add this directory to your project
add_subdirectory(thread)

# Add an executable target
add_executable(MyThreadDemo "MyThreadDemo.cpp")

# Link 'MyThread' to the target
target_link_libraries(MyThreadDemo MyThread)
```
