#ifndef _ATTACKS_H_
#define _ATTACKS_H_

#include "../../configuration.hpp"
#include "Types/types.hpp"


class attacks
{

public:
enum class kinds {
    UNINIT,
    PHYSICAL,
    SPECIAL,
    STATUS
};

private:
    kinds kind;
    types::types type;

    int8_t accuracy;
    uint8_t power;
    types::status status;

    std::string name;

// access methods
public: 
    int8_t  get_accuracy();
    uint8_t get_power();

public:
    attacks(kinds kind, types::types type, int8_t accuracy, uint8_t power_status, std::string name);
    ~attacks();
};

#endif