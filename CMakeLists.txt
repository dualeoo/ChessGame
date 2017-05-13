cmake_minimum_required(VERSION 3.6)
project(Chess)

set(Chess_VERSION_MAJOR 1)
set(Chess_VERSION_MINOR 0)

set(CMAKE_C_STANDARD 99)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file(
        "${PROJECT_SOURCE_DIR}/ChessConfig.h.in"
        "${PROJECT_BINARY_DIR}/ChessConfig.h"
)

# add the binary tree to the search path for include files
# so that we will find ChessConfig.h
include_directories("${PROJECT_BINARY_DIR}")

set(SOURCE_FILES Board.c Chess.c Game.c Piece.c AI.c Match.c Player.c Helper.c Database.c String.c)
add_executable(Chess ${SOURCE_FILES})