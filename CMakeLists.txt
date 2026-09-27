cmake_minimum_required(VERSION 4.2.3)
project(renderer LANGUAGES CXX)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE main.cpp framebuffer.cpp)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_23)
