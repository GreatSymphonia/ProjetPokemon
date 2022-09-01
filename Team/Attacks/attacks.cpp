#include "attacks.hpp"

attacks::attacks(kinds kind, types::types type, types::status status, int8_t accuracy
               , uint8_t power, std::string name, int32_t pp, int32_t priority
               , statistics mods, bool is_protect)
{
    this->kind = kind;
    this->type = type;

    if (accuracy >= 0)
        this->accuracy = accuracy;

    if (power >= 0)
        this->power  = power;

    this->status = status;

    this->name = name;

    this->pp = pp;
    this->cur_pp = pp;

    this->priority = priority;
    this->modifiers = mods;
    this->isProtect = is_protect;

}

attacks::~attacks()
{
}