#ifndef _POKEMON_H_
#define _POKEMON_H_

#include "../../configuration.hpp"
#include "stats.hpp"
#include "../Attacks/Types/types.hpp"
#include "../Attacks/attacks.hpp"

class pokemon
{
public:
    float getAtk();
    float getDef();
    float getS_atk();
    float getS_def();
    float getSpe();

    void modAtk(int32_t modifier);
    void modDef(int32_t modifier);
    void modS_atk(int32_t modifier);
    void modS_def(int32_t modifier);
    void modSpe(int32_t modifier);

    // edits cur_hp to remove hp from damage
    // returns true if the defender is KO (0 hp)
    bool removeHp(int32_t damage);
    bool removeHp(int32_t damage, int32_t& hp_left);

    // sets this pokemon's status, returns true if succeded (not already set)
    bool set_status(types::status status);

    void set_nick(std::string nick);

private:
    const std::map<int32_t, float> modifiers = { 
        {-6, 0.25f},
        {-5, 0.28f},
        {-4, 0.33f},
        {-3, 0.40f},
        {-2, 0.50f},
        {-1, 0.66f},
        { 0, 1.0f},
        { 1, 1.5f},
        { 2, 2.0f},
        { 3, 2.5f},
        { 4, 3.0f},
        { 5, 3.5f},
        { 6, 4.0f}
    };

    static constexpr float PERCENT = 100; 

private:
    // Nom et surnom du pokémon
    std::string Name;
    std::string NickName;

    // Les deux types du pokémon
    std::array<types::types, 2> types;
    // Les index des 4 attaques du pokémon
    std::array<int, 4> attacks_ID;

    // le statut du pokémon
    types::status status;

    uint32_t level;

    statistics stats;
    // hp -> current hp; else modifiers
    statistics mods;

public:
    pokemon(std::string Name, std::array<int, 4> attacks
          , statistics stats, uint32_t level);
    ~pokemon();
};





#endif //!_POKEMON_H_