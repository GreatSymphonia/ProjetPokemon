#include "attacks.hpp"

attacks::attacks(kinds kind, types::types type, int8_t accuracy, uint8_t power_status, std::string name)
{
    this->kind = kind;
    this->type = type;

    this->accuracy = accuracy;

    if (this->kind == kinds::STATUS)
    {
        this->status = static_cast<types::status>(power_status);
        this->power  = 0;
    }
    else
    {
        this->status = types::status::UNINIT;
        this->power  = power_status;
    }

    this->name = name;
}

attacks::~attacks()
{
}