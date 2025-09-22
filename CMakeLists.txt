cmake_minimum_required(VERSION 3.30)
project(SysTaskThreaded)

set(CMAKE_CXX_STANDARD 20)

add_executable(SysTaskThreaded main.cpp
        includes/QueueManager.hpp
        src/QueueManager.cpp
        includes/TaskInfo.hpp
        src/TaskInfo.cpp
        includes/ThreadTaskManager.hpp
        src/ThreadTaskManager.cpp)
