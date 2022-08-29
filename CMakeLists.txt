cmake_minimum_required(VERSION 3.0.0)
project(PokemonCpp VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(PokemonCpp 
main.cpp
configuration.hpp

Interface/interface.cpp
Interface/interface.hpp

tools/tools.cpp
tools/tools.hpp
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
