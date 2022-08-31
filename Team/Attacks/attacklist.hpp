#ifndef _ATTACKLIST_H_
#define _ATTACKLIST_H_

#include "../../configuration.hpp"
#include "attacks.hpp"

namespace fs = std::filesystem;

std::vector<attacks> get_attack_list(fs::path filepath);


#endif //!_ATTACKLIST_H_