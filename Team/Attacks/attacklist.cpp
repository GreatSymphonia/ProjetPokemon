#include "attacklist.hpp"

/*
ID intéressants:
1: normal

2: sleep
34: tox_poison
67: poison
68: paralysis
168: burn

112: protect


11: atk +1
12: def +1
13: s_atk +1

19: atk -1
20: def -1
21: spe -1

51: atk +2
52: def +2
53: spe +2
54: s_atk +2
55: s_def +2

59: atk -2
60: def -2
61: spe -2
62: s_atk -2
63: s_def -2

33: heal 50%

*/

// parses the actual CSV
std::vector<attacks> getAttackList(fs::path filepath)
{
    assert(fs::exists(filepath));

    std::ifstream file(filepath.relative_path().generic_string(), std::ifstream::in);
    assert(file.is_open());

    std::vector<attacks> to_return;

    std::string line;

    //consume the 1st line
    std::getline(file, line);
    while (std::getline(file, line))
    {
        struct _data{
            int32_t id;
            char name[40];
            int32_t gen;        // unused
            int32_t type;
            int32_t power;
            int32_t pp;
            int32_t accuracy;
            int32_t priority;
            int32_t target;
            int32_t kind;
            int32_t effect;     // used to manage status effects
            int32_t effect_odds;// unused
            int32_t contest1;   // unused
            int32_t contest2;   // unused
            int32_t contest3;   // unused
        } data;
        data = {};

        sscanf(line.c_str(), "%d,%[^,],%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d"
            , &data.id, data.name, &data.gen, &data.type, &data.power, &data.pp, &data.accuracy
            , &data.priority, &data.target, &data.kind, &data.effect, &data.effect_odds
            , &data.contest1, &data.contest2, &data.contest3);

        // TODO: constants
        if (data.target == 8  ||
            data.target == 10 ||
            data.target == 11 ||
            data.target == 12)
        {
            types::status thisStatus = types::status::UNINIT;

            statistics thisStats = {};

            switch (data.effect)
            {
            case 2:
                thisStatus = types::status::SLEEP;
                break;
            case 34:
                thisStatus = types::status::TOX_POISON;
                break;
            case 67:
                thisStatus = types::status::POISON;
                break;
            case 68:
                thisStatus = types::status::PARALYSIS;
                break;
            case 168:
                thisStatus = types::status::BURN;
                break;

            case 11:
                thisStats.atk = 1;
                break;
            case 12:
                thisStats.def = 1;
                break;
            case 13:
                thisStats.s_atk = 1;
                break;

            case 19:
                thisStats.atk = -1;
                break;
            case 20:
                thisStats.def = -1;
                break;
            case 21:
                thisStats.spe = -1;
                break;

            case 51:
                thisStats.atk = 2;
                break;
            case 52:
                thisStats.def = 2;
                break;
            case 53:
                thisStats.spe = 2;
                break;
            case 54:
                thisStats.s_atk = 2;
                break;
            case 55:
                thisStats.s_def = 2;
                break;

            case 59:
                thisStats.atk = -2;
                break;
            case 60:
                thisStats.def = -2;
                break;
            case 61:
                thisStats.spe = -2;
                break;
            case 62:
                thisStats.s_atk = -2;
                break;
            case 63:
                thisStats.s_def = -2;
                break;
            case 33:
                thisStats.hp = 2;
                break;

            default:
                break;
            }


            to_return.push_back(attacks(static_cast<attacks::kinds>(data.kind)
                                    , static_cast<types::types>(data.type)
                                    , thisStatus
                                    , data.accuracy
                                    , data.power
                                    , std::string(data.name)
                                    , data.pp
                                    , data.priority
                                    , thisStats
                                    , data.effect == 112
                                    ));

        }        
    }
    return to_return;
}

