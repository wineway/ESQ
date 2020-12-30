cmake_minimum_required(VERSION 3.13)
project(ESQ)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_VERBOSE_MAKEFILE ON)

SET(LEVELDB_BUILD_TESTS OFF CACHE BOOL "disable leveldb use gtest" FORCE)

add_subdirectory("third_party/leveldb")

option(ESQ_BUILD_TESTS "Build esq's unit tests" ON)

add_library(ESQ "")
target_sources(ESQ PUBLIC
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

if(ESQ_BUILD_TESTS)
    enable_testing()

    # Prevent overriding the parent project's compiler/linker settings on Windows.
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    set(install_gtest OFF)
    set(install_gmock OFF)
    set(build_gmock ON)

    # This project is tested using GoogleTest.
    add_subdirectory("third_party/googletest")

    function(esq_test test_file)
        get_filename_component(test_target_name "${test_file}" NAME_WE)

        add_executable("${test_target_name}" "")
        target_sources("${test_target_name}"
                PRIVATE
                "${test_file}"
                )
        target_link_libraries("${test_target_name}" ESQ gmock gtest)
        add_test(NAME "${test_target_name}" COMMAND "${test_target_name}")
    endfunction(esq_test)

    esq_test("persist/FileNameTest.cpp")
endif(ESQ_BUILD_TESTS)
#add_executable(test main.cpp)
