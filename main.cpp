#include "configuration.hpp"
#include "Interface/interface.hpp"
#include "MenuPrincipal/menuprincipal.hpp"

#if APP_MODE

int main(void)
{
    std::cout << "Bienvenue à ce simulateur de " << std::endl;
    
    interface_dialogue MenuPrincipal;
    MenuPrincipal.add_choice("Création d'équipe");
    MenuPrincipal.add_choice("Importation d'équipe");
    MenuPrincipal.add_choice("Exportation d'équipe");
    MenuPrincipal.add_choice("Partie contre l'ordinateur");
    MenuPrincipal.add_choice("Partie contre un humain");
    MenuPrincipal.add_choice("À propos");

    MainMenu::access_option(MenuPrincipal.prompt());



    return EXIT_SUCCESS;
}




#endif
