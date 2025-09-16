cmake_minimum_required(VERSION 3.10)
project(ArrayOperations)

add_executable(array_app
    main.cpp
    array.cpp
    utils.cpp
    menu.cpp
)

target_include_directories(array_app PRIVATE .)