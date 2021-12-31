cmake_minimum_required(VERSION 3.10)

project(
    run
    LANGUAGES CXX
)

add_executable(${PROJECT_NAME} 
    main.cpp
    myList.h
    myList.hpp
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
        CXX_STANDARD 14
)
