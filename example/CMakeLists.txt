cmake_minimum_required(VERSION 3.5.1)

project(example)

set(CMAKE_CXX_STANDARD 14)

find_package(fineftp REQUIRED CONFIG)

set(sources
    src/main.cpp
)

set(headers
        src/plugins/vfsfileintf.h
        src/plugins/vfsfileinfo.h)

add_executable (${PROJECT_NAME}
    ${sources}
)

target_link_libraries (${PROJECT_NAME}
    fineftp::server
)
