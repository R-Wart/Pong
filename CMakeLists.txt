cmake_minimum_required(VERSION 3.25)
project(Pong)

set(CMAKE_CXX_STANDARD 17)
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(Pong main.cpp Bat.cpp Bat.h Ball.cpp Ball.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR ${CMAKE_SOURCE_DIR}/Dependencies/SFML/Build)
find_package(SFML COMPONENTS system window graphics audio REQUIRED)

target_link_libraries(Pong sfml-system sfml-window sfml-graphics sfml-audio)

add_custom_target(copy_resources
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/resources ${CMAKE_CURRENT_BINARY_DIR}/resources
        )

add_dependencies(Pong copy_resources)