cmake_minimum_required(VERSION 3.10)
project(ProjetMultiTool)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL3 REQUIRED)

include_directories(includes)


set(SERVER_SOURCES 
    src/server/sv_main.cpp
    src/server/main.cpp
    src/utils/server.cpp
    src/utils/player.cpp
	src/utils/main.cpp
	src/utils/map.cpp
	src/utils/game.cpp
)
add_executable(server ${SERVER_SOURCES})
target_link_libraries(server PRIVATE SDL3::SDL3)

set(CLIENT_SOURCES 
    src/client/cl_main.cpp
	src/client/client.cpp
)
add_executable(client ${CLIENT_SOURCES})
target_link_libraries(client PRIVATE SDL3::SDL3)
