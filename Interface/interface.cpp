#include "interface.hpp"


void interface_dialogue::add_choice(std::string to_add)
{
    this->choices.push_back(to_add);
}

void interface_dialogue::rem_choice(int32_t position)
{
    // validate that there is enough elements to remove the desired one
    assert(position < this->choices.size());
    // remove the desired element
    this->choices.erase(this->choices.begin() + position);
}

int32_t interface_dialogue::clr_prompt()
{
    return interface_dialogue::prompt();
}

int32_t interface_dialogue::prompt()
{
    int32_t to_return = -1;
    //std::cout << "\n\n" << std::endl;
    // show options
    for (std::size_t it = 0; it != this->choices.size(); it++)
    {
        std::cout << it << ".\t: " << this->choices[it] << std::endl;
    }

    std::cout << "\n\nOption : ";
    // Wait to get 1 and only one element in scanf
    while(scanf("%i", &to_return) != 1);
    return to_return;
}


interface_dialogue::interface_dialogue(std::vector<std::string> input)
{
    this->choices = input; // copier le vecteur en entrée
}

interface_dialogue::interface_dialogue()
{
}

interface_dialogue::~interface_dialogue()
{
}