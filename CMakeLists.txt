cmake_minimum_required(VERSION 3.16)
project(ESQ)

set(CMAKE_CXX_STANDARD 17)

add_executable(ESQ main.cpp persist/Message.h persist/Message.cpp persist/Persister.cpp persist/Persister.h)