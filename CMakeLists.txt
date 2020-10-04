cmake_minimum_required(VERSION 3.13)
project(ESQ)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_VERBOSE_MAKEFILE ON)

add_subdirectory("thirdparty/leveldb")

add_library(ESQ "")
target_sources(ESQ PUBLIC main.cpp
        common/RingBuffer.cpp common/RingBuffer.h
        persist/Message.h persist/Message.cpp
        persist/Persistor.cpp persist/Persistor.h
        persist/FileName.h
        persist/AppendableFile.cpp persist/AppendableFile.h
        persist/Channel.cpp persist/Channel.h)

include_directories(
        "${PROJECT_BINARY_DIR}/include"
        "."
)

target_link_libraries(ESQ PUBLIC leveldb)

add_executable(test main.cpp)
target_link_libraries(test ESQ)
#target_link_libraries(ESQ PUBLIC ${LevelDB_LIBRARIES})
