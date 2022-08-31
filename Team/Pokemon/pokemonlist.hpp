#ifndef _POKEMONLIST_H_
#define _POKEMONLIST_H_

#include "../../configuration.hpp"
#include "pokemon.hpp"

namespace fs = std::filesystem;

std::vector<pokemon> get_pokemon_list(fs::path filepath);

#endif