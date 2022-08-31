#include "pokemon.hpp"

float pokemon::getAtk()
{
    assert(this->mod_atk >= -6 && this->mod_atk <= 6);
    return this->stats.atk * modifiers.at(this->mod_atk);
}

float pokemon::getDef()
{
    assert(this->mod_def >= -6 && this->mod_def <= 6);
    return this->stats.def * modifiers.at(this->mod_def);
}

float pokemon::getS_atk()
{
    assert(this->mod_s_atk >= -6 && this->mod_s_atk <= 6);
    return this->stats.s_atk * modifiers.at(this->mod_s_atk);
}

float pokemon::getS_def()
{
    assert(this->mod_s_def >= -6 && this->mod_s_def <= 6);
    return this->stats.s_def * modifiers.at(this->mod_s_def);
}

float pokemon::getSpe()
{
    assert(this->mod_spe >= -6 && this->mod_spe <= 6);
    return this->stats.spe * modifiers.at(this->mod_spe);
}


void pokemon::modAtk(int32_t modifier)
{
    this->mod_atk += modifier;
    if(this->mod_atk > 6)
        this->mod_atk = 6;
    if(this->mod_atk < -6)
        this->mod_atk = -6;
}

void pokemon::modDef(int32_t modifier)
{
    this->mod_def += modifier;
    if(this->mod_def > 6)
        this->mod_def = 6;
    if(this->mod_def < -6)
        this->mod_def = -6;
}

void pokemon::modS_atk(int32_t modifier)
{
    this->mod_s_atk += modifier;
    if(this->mod_s_atk > 6)
        this->mod_s_atk = 6;
    if(this->mod_s_atk < -6)
        this->mod_s_atk = -6;
}

void pokemon::modS_def(int32_t modifier)
{
    this->mod_s_def += modifier;
    if(this->mod_s_def > 6)
        this->mod_s_def = 6;
    if(this->mod_s_def < -6)
        this->mod_s_def = -6;
}

void pokemon::modSpe(int32_t modifier)
{
    this->mod_spe += modifier;
    if(this->mod_spe > 6)
        this->mod_spe = 6;
    if(this->mod_spe < -6)
        this->mod_spe = -6;
}

bool pokemon::removeHp(int32_t damage)
{
    this->cur_hp += damage;

    if (this->cur_hp < 0)
        this->cur_hp = 0;

    return !this->cur_hp;
}

bool pokemon::removeHp(int32_t damage, int32_t& hp_left)
{
    this->cur_hp += damage;

    if (this->cur_hp < 0)
        this->cur_hp = 0;

    hp_left = this->cur_hp;
    return !this->cur_hp;
}

bool pokemon::set_status(types::status status)
{
    if (this->status == types::status::UNINIT)
    {
        this->status = status;
        return true;
    }

    return false;
}


pokemon::pokemon(std::string Name, std::string NickName, std::array<int, 4> attacks
               , statistics stats, uint32_t level)
{
    this->Name = Name;
    this->NickName = NickName;
    this->attacks_ID = attacks;
    
    this->level = level;
    
    this->stats = stats;

    this->cur_hp = this->stats.hp;

}

pokemon::~pokemon()
{
}