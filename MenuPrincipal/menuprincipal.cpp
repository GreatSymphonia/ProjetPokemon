#include "menuprincipal.hpp"


void MainMenu::access_option(interface_dialogue objet)
{
    bool stay = true;

    while(stay)
    {
        switch (objet.clr_prompt())
        {
        case 0:
            stay = false;
            break;
        case 1:
            // Teammaking
            break;
        case 2:
            // Import team
            break;
        case 3:
            // Export team
            break;
        case 4:
            // CPU battle
            break;
        case 5:
            // VS battle
            break;
        case 6:
            // About
            break;
        
        default:
            std::cout << "\n ERREUR: Valeur invalide" << std::endl;
            break;
        }
    }
}
