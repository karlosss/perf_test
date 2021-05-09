cmake_minimum_required(VERSION 3.16)
project(perf_test)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -march=native")

add_executable(perf_test main.cpp tsc_x86.h common.h funs.h init.h benchmark.h random_range.h bench_funs.h)
