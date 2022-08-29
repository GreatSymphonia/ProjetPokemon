#ifndef _INTERFACE_HPP_
#define _INTERFACE_HPP_

#include "../configuration.hpp"
#include "../tools/tools.hpp"

class interface_dialogue
{
private:
    std::vector<std::string> choices;

// Access methods
public:
    void add_choice(std::string to_add);
    void rem_choice(int32_t position);
    int32_t clr_prompt();
    int32_t prompt();


// Constructor/Destructor
public:
    interface_dialogue(std::vector<std::string> input);
    interface_dialogue();
    ~interface_dialogue();
};



#endif //!_INTERFACE_HPP_