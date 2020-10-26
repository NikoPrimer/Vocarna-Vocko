#ifndef FUNCTIONALITY_H_INCLUDED
#define FUNCTIONALITY_H_INCLUDED

#include <string>
#include <iostream>


class Store;    //forward declaration needed for reference in functions

class Function      //A class for holding a functionality for the store and the name of that functionality
{
public:

    Function() {};
    Function(const std::string& name,
             void (*pointer)(Store&, std::istream&, std::ostream&)):
        functionName(name), functionPtr(pointer) {};

    //Read the name of the Function
    std::string name() const { return functionName; }

    //A function used for set the name and pointer
    void make(std::string make_name,
              void (*make_pointer)(Store&, std::istream&, std::ostream&))
    {
        functionName = make_name;
        functionPtr = make_pointer;
    }

    //Used to access the function stored in the class
    void access(Store& store, std::istream& in, std::ostream& os)
    {
        functionPtr(store, in, os);
    }
private:
    std::string functionName;
    void (*functionPtr)(Store&, std::istream&, std::ostream&);
};



void remove_p(Store&, std::istream&, std::ostream&);
void add(Store&, std::istream&, std::ostream&);
void change(Store&, std::istream&, std::ostream&);
void status(Store&, std::istream&, std::ostream&);
void query(Store&, std::istream&, std::ostream&);
void buy(Store&, std::istream&, std::ostream&);
void go_back(Store&, std::istream&, std::ostream&);

void change_p_name(Store&, std::istream&, std::ostream&);
void change_p_quantity(Store&, std::istream&, std::ostream&);
void change_p_price(Store&, std::istream&, std::ostream&);

void access_manage(Store&, std::istream&, std::ostream&);
void access_query(Store&, std::istream&, std::ostream&);
void access_buy(Store&, std::istream&, std::ostream&);
void access_language(Store&, std::istream&, std::ostream&);

void set_croatian_language(Store&, std::istream&, std::ostream&);
void set_english_language(Store&, std::istream&, std::ostream&);
void exit(Store&, std::istream&, std::ostream&);

#endif // FUNCTIONALITY_H_INCLUDED
