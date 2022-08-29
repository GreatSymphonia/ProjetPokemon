#include "attacks.hpp"

attacks::attacks(kinds kind, types::types type, int8_t accuracy, uint8_t power, std::string name)
{
    this->kind = kind;
    this->type = type;

    this->accuracy = accuracy;
    this->power = power;

    this->name = name;
}

attacks::~attacks()
{
}