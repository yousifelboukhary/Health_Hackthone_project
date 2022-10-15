cmake_minimum_required(VERSION 3.21)
project(symptoms_clustering)

set(CMAKE_CXX_STANDARD 14)

add_executable(symptoms_clustering main.cpp symptoms_matrix.cpp symptoms_matrix.h)
