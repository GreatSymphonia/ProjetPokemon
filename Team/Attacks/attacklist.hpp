#ifndef _ATTACKLIST_H_
#define _ATTACKLIST_H_

#include "../../configuration.hpp"
#include "attacks.hpp"

static const int32_t VOID_VALUE = -127;

namespace fs = std::filesystem;

static const std::string moves_path = "../reference_files/pokemon_moves.csv";

std::vector<attacks> getAttackList(fs::path filepath);


#endif //!_ATTACKLIST_H_