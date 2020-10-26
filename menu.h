#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <string>
#include <vector>
#include <iostream>

#include "functionality.h"


class Menu      //A class that holds pointers to the functionalities that the store has
{
public:
    typedef std::vector<Function*> vector_fptr;

    Menu() {};
    Menu(const std::string& name, vector_fptr options):
        menuName(name), menuOptions(options) {};

    std::string name() const { return menuName; }

    void make(std::string, vector_fptr);
    void access(Store&, std::istream&, std::ostream&);
    void headline(std::ostream&);

    void write_options(std::ostream&);
    vector_fptr::size_type select_option(Store&, std::istream&, std::ostream&);

private:
    std::string menuName;
    vector_fptr menuOptions;
};


#endif // MENU_H_INCLUDED
