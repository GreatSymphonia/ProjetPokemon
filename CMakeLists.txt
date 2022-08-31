cmake_minimum_required(VERSION 3.23)
project(PokemonCpp VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")


include(CTest)
enable_testing()

add_executable(PokemonCpp 
configuration.hpp

Interface/interface.cpp

MenuPrincipal/menuprincipal.cpp

Team/menuteam.cpp
Team/team.cpp

Team/Attacks/attacks.cpp
Team/Attacks/attacklist.cpp

Team/Pokemon/pokemon.cpp

tools/tools.cpp

main.cpp
)

target_link_libraries(PokemonCpp stdc++fs)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
