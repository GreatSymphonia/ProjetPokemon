#include "attacks.hpp"

attacks::attacks(kinds kind, types::types type, int8_t accuracy, uint8_t power_status, std::string name)
{
    this->kind = kind;
    this->type = type;

    this->accuracy = accuracy;
    this->power_status = power_status;

    this->name = name;
}

attacks::~attacks()
{
}