cmake_minimum_required(VERSION 3.6)
project(Chess)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c Chess.c)
add_executable(Chess chess.c)