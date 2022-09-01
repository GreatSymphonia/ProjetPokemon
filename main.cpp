#include "configuration.hpp"
#include "Interface/interface.hpp"
#include "MenuPrincipal/menuprincipal.hpp"
#include "Team/Attacks/attacklist.hpp"

namespace fs = std::filesystem;

#if APP_MODE

int main(void)
{
    std::cout << "Bienvenue à ce simulateur de Pokémon" << std::endl;

    std::vector<attacks> ListeAttaques;

    fs::path AttackPath = "../reference_files/attacks.txt";

    ListeAttaques = getAttackList(moves_path);
    
    interface_dialogue MenuPrincipal;
    MenuPrincipal.add_choice("Création d'équipe");
    MenuPrincipal.add_choice("Importation d'équipe");
    MenuPrincipal.add_choice("Exportation d'équipe");
    MenuPrincipal.add_choice("Partie contre l'ordinateur");
    MenuPrincipal.add_choice("Partie contre un humain");
    MenuPrincipal.add_choice("À propos");

    MainMenu::access_option(MenuPrincipal);



    return EXIT_SUCCESS;
}




#endif
