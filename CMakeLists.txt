cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 14)
project(python_embed_test)

find_package(Python COMPONENTS Development)

configure_file(testComponent.py ${CMAKE_CURRENT_BINARY_DIR}/testComponent.py COPYONLY)

add_executable(
        python_embed_test
        main.cpp
        Component.cpp)

target_link_libraries(
        python_embed_test
        Python::Python
)