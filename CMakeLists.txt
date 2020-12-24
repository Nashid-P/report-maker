cmake_minimum_required(VERSION 3.9)
project(report_maker)

set(CMAKE_CXX_STANDARD 11)

add_executable(report_maker
        main.cpp ProfileManager.h ProfileManager.cpp)
