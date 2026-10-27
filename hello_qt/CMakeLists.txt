cmake_minimum_required(VERSION 3.28)
project(hello_qt LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(hello_qt
    src/main.cpp
    src/MainWindow.cpp
    src/MainWindow.hpp
)
target_link_libraries(hello_qt PRIVATE Qt6::Widgets)
