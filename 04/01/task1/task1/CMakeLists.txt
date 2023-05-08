cmake_minimum_required(VERSION 3.5)
find_package(Catch2 3 REQUIRED)
add_executable(task1 task1.cpp)
target_link_libraries(task1 PRIVATE Catch2::Catch2)