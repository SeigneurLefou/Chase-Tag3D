cmake_minimum_required(VERSION 3.10)
project(ProjetMultiTool)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL3 REQUIRED)

include_directories(includes)

set(WINDOW_SOURCES 
    src/window/wd_test.cpp
)
add_executable(window ${WINDOW_SOURCES})
target_link_libraries(window PRIVATE SDL3::SDL3)

set(SERVER_SOURCES 
    src/server/sv_main.cpp
)
add_executable(server ${SERVER_SOURCES})

set(CLIENT_SOURCES 
    src/client/cl_main.cpp
)
add_executable(client ${CLIENT_SOURCES})
