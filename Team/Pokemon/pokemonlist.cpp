#include "pokemonlist.hpp"

std::vector<pokemon> get_pokemon_list(fs::path filepath)
{
    assert(fs::exists(filepath));

    std::ifstream file(filepath.relative_path().generic_string(), std::ifstream::in);
    assert(file.is_open());

    std::vector<pokemon> to_return;

    std::string line;


    while (std::getline(file, line))
    {
        std::istringstream iss(line);

        if(!(iss >> )) 
        {
            std::cout << "ERREUR: parsing" << std::endl;
        }
    }
    
    return to_return;

}

