cmake_minimum_required(VERSION 3.17)
project(python_embed_test)

find_package(Python COMPONENTS Development)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        python_embed_test
        main.cpp
        Dummy.cpp
)

target_link_libraries(
        python_embed_test
        Python::Python
)