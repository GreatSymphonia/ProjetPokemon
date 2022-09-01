#include "pokemon.hpp"

float pokemon::getAtk()
{
    assert(this->mods.atk >= -6 && this->mods.atk <= 6);
    return this->stats.atk * modifiers.at(this->mods.atk) / PERCENT;
}

float pokemon::getDef()
{
    assert(this->mods.def >= -6 && this->mods.def <= 6);
    return this->stats.def * modifiers.at(this->mods.def) / PERCENT;
}

float pokemon::getS_atk()
{
    assert(this->mods.s_atk >= -6 && this->mods.s_atk <= 6);
    return this->stats.s_atk * modifiers.at(this->mods.s_atk) / PERCENT;
}

float pokemon::getS_def()
{
    assert(this->mods.s_def >= -6 && this->mods.s_def <= 6);
    return this->stats.s_def * modifiers.at(this->mods.s_def) / PERCENT;
}

float pokemon::getSpe()
{
    assert(this->mods.spe >= -6 && this->mods.spe <= 6);
    return this->stats.spe * modifiers.at(this->mods.spe) / PERCENT;
}


void pokemon::modAtk(int32_t modifier)
{
    this->mods.atk += modifier;
    if(this->mods.atk > 6)
        this->mods.atk = 6;
    if(this->mods.atk < -6)
        this->mods.atk = -6;
}

void pokemon::modDef(int32_t modifier)
{
    this->mods.def += modifier;
    if(this->mods.def > 6)
        this->mods.def = 6;
    if(this->mods.def < -6)
        this->mods.def = -6;
}

void pokemon::modS_atk(int32_t modifier)
{
    this->mods.s_atk += modifier;
    if(this->mods.s_atk > 6)
        this->mods.s_atk = 6;
    if(this->mods.s_atk < -6)
        this->mods.s_atk = -6;
}

void pokemon::modS_def(int32_t modifier)
{
    this->mods.s_def += modifier;
    if(this->mods.s_def > 6)
        this->mods.s_def = 6;
    if(this->mods.s_def < -6)
        this->mods.s_def = -6;
}

void pokemon::modSpe(int32_t modifier)
{
    this->mods.spe += modifier;
    if(this->mods.spe > 6)
        this->mods.spe = 6;
    if(this->mods.spe < -6)
        this->mods.spe = -6;
}

bool pokemon::removeHp(int32_t damage)
{
    this->mods.hp += damage;

    if (this->mods.hp < 0)
        this->mods.hp = 0;

    return !this->mods.hp;
}

bool pokemon::removeHp(int32_t damage, int32_t& hp_left)
{
    this->mods.hp += damage;

    if (this->mods.hp < 0)
        this->mods.hp = 0;

    hp_left = this->mods.hp;
    return !this->mods.hp;
}

bool pokemon::set_status(types::status status)
{
    // change status only if uninitialised
    if (this->status == types::status::UNINIT)
    {
        this->status = status;
        return true;
    }
    // set status if back to uninitialised
    if (status == types::status::UNINIT)
    {
        this->status = status;
        return true;
    }

    return false;
}

void pokemon::set_nick(std::string nick)
{
    assert(nick.size() <= 20); // not a too long nickname
    this->NickName = nick;
}



pokemon::pokemon(std::string Name, std::array<int, 4> attacks
               , statistics stats, uint32_t level)
{
    this->Name = Name;
    this->attacks_ID = attacks;
    
    this->level = level;
    
    this->stats = stats;

    this->mods.hp = this->stats.hp;

}

pokemon::~pokemon()
{
}