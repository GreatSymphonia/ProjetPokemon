#include "attacklist.hpp"

// parses attackes line per line using the provided filepath
std::vector<attacks> get_attack_list(std::string myfile)
{
    fs::path filepath = myfile;

    assert(fs::exists(filepath));

    std::ifstream file(filepath.relative_path().generic_string(), std::ifstream::in);
    assert(file.is_open());

    std::vector<attacks> to_return;

    std::string line;


    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        uint32_t kind = 0, type = 0, power_status = 0;
        int32_t accuracy = -2;
        std::string name;

        if(!(iss >> kind >> type >> accuracy >> power_status >> name)) 
        {
            std::cout << "ERREUR: parsing" << std::endl;
        }

        to_return.push_back(attacks(static_cast<attacks::kinds>(kind), static_cast<types::types>(type), accuracy, power_status, name));

    }
    
    return to_return;

}

