#ifndef _ATTACKS_H_
#define _ATTACKS_H_

#include "../../configuration.hpp"
#include "../Pokemon/stats.hpp"
#include "Types/types.hpp"


class attacks
{

public:
enum class kinds {
    UNINIT,
    STATUS,
    PHYSICAL,
    SPECIAL
};

private:
    kinds kind;
    types::types type;

    int8_t accuracy;
    uint8_t power;
    // status condition it causes
    types::status status;

    bool isProtect;

    int32_t priority;
    int32_t pp, cur_pp;

    std::string name;

    statistics modifiers;

// access methods
public: 
    int8_t  get_accuracy();
    uint8_t get_power();

public:
    attacks(kinds kind, types::types type, types::status status, int8_t accuracy
          , uint8_t power, std::string name, int32_t pp, int32_t priority
          , statistics mods, bool is_protect);
    ~attacks();
};

#endif