cmake_minimum_required(VERSION 3.0.0)
project(PokemonCpp VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(PokemonCpp 
configuration.hpp

Interface/interface.cpp
Interface/interface.hpp

MenuPrincipal/menuprincipal.cpp
MenuPrincipal/menuprincipal.hpp

Team/menuteam.cpp
Team/menuteam.hpp
Team/team.cpp
Team/team.hpp

Team/Attacks/attacks.cpp
Team/Attacks/attacks.hpp

Team/Attacks/Types/types.cpp
Team/Attacks/Types/types.hpp


tools/tools.cpp
tools/tools.hpp

main.cpp
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
