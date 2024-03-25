cmake_minimum_required (VERSION 3.8)
project(CodeCraftSDK)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

if (!WIN32)
    link_libraries(pthread rt m)
endif (!WIN32)

include_directories(include)

AUX_SOURCE_DIRECTORY(. src)
AUX_SOURCE_DIRECTORY(./src src)
ADD_EXECUTABLE(main ${src})