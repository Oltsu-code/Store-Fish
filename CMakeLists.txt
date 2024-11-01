Remove-Item -Recurse -Force .\build

cmake_minimum_required(VERSION 3.10)
project(StoreFish)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES "src/*.cpp" "src/*.h")

add_executable(StoreFish ${SOURCES})

