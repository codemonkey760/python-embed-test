cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 14)
project(python_embed_test)

find_package(Python COMPONENTS Development)

configure_file(test.py ${CMAKE_CURRENT_BINARY_DIR}/test.py COPYONLY)
configure_file(test2.py ${CMAKE_CURRENT_BINARY_DIR}/test2.py COPYONLY)

add_executable(
        python_embed_test
        main.cpp
        Dummy.cpp
)

target_link_libraries(
        python_embed_test
        Python::Python
)