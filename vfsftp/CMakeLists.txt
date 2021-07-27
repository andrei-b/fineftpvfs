cmake_minimum_required(VERSION 3.5.1)

project(vfsftp)

set(CMAKE_CXX_STANDARD 17)

find_package(fineftp REQUIRED CONFIG)

set(sources
    src/main.cpp
    src/plugins/gcfselement.cpp
    src/plugins/gcfilesystem.cpp
    src/plugins/utils.cpp
        src/config.cpp src/config.h)

set(headers
        src/plugins/vfsfileintf.h
        src/plugins/vfsfileinfo.h
        src/plugins/gcfilesystem.h
        src/plugins/gcfselement.h
        src/plugins/utils.h
        nlohmann/json.hpp)

add_subdirectory(fmt)

add_executable (${PROJECT_NAME}
    ${sources}
)

target_link_libraries (${PROJECT_NAME}
    fineftp::server
    stdc++fs
    fmt
)
