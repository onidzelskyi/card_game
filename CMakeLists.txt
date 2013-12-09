project(card_game)
cmake_minimum_required(VERSION 2.8)
SET(CMAKE_CXX_FLAGS "-std=c++0x -D_DEBUG_")
set(CMAKE_C_FLAGS_DEBUG "-D_DEBUG_")
aux_source_directory(. SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST})

