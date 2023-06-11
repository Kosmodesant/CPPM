cmake_minimum_required(VERSION 3.5)
project(Parser_ini VERSION 1.0 LANGUAGES CXX)
add_executable(parser
	main.cpp
	SecondFunction/SecondaryFunction.h SecondFunction/SecondaryFunction.cpp
	Parser/Parser.h Parser/Parser.cpp)
if(MSVC)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT parser)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
else()
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
endif()