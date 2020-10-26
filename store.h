#ifndef STORE_H_INCLUDED
#define STORE_H_INCLUDED

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>

#include "menu.h"
#include "produce.h"
#include "languages.h"


class Store
{
public:
    Store(): dictionary(not_set()), selected_language(false) { pre_build(); }

    typedef std::list<Produce> product_registry;
    typedef std::list<Produce>::iterator registry_iter;

    void pre_build();
    int make(std::istream& = std::cin, std::ostream& = std::cout);
    void access(std::istream& = std::cin, std::ostream& = std::cout);

    void select_language(std::istream&, std::ostream&);
    void set_language(const Language&);
    void deselect_language();
    void add_product(const Produce&);
    void remove_product();
    void buy_product(double);
    void product_status(std::ostream&) const;
    void warehouse_status(std::ostream&);
    bool check_for_product(const std::string&);
    void show_wares(std::ostream&);

    void change_product_name(const std::string&);
    void change_product_quantity(double);
    void change_product_price(double);

    //Check if a language was loaded into the dictionary
    bool check_language()
    {
        return selected_language;
    }

    //Get a pointer to a Function - used in build functions
    Function* get_function_pointer(const std::string& f_name)
    {
        return &(functions.find(f_name)->second);
    }

    //Access a Menu from the map
    void access_Menu(const std::string& m_name, std::istream& in, std::ostream& os)
    {
         (menus.find(m_name)->second).access(*this, in, os);
    }

    //Reads the name of the selected product
    std::string product_name() const
    {
        return (*selected_product).name();
    }

    //Reads the quantity of the selected product
    double product_quantity() const
    {
        return (*selected_product).quantity();
    }

    //Sets a pointer to the selected product
    void select_product(registry_iter& select)
    {
        selected_product = select;
    }

    //Selects the last product added
    void select_new_product()
    {
        --selected_product;
    }

    //Deselects the product by setting the pointer to end of file
    void deselect_product()
    {
        selected_product = warehouse.end();
    }

    //Checks if a valid product is selected
    bool check_selected() const
    {
        return (selected_product != warehouse.end());
    }

    //Returns the appropriate phrase from the dictionary
    std::string phrase(const std::string key) const
    {
        return dictionary.phrase(key);
    }

    //Writes a headline from
    std::string headline(const std::string option) const
    {
        return ("\n\n***** " + option + " *****\n\n");
    }

private:
    std::map
    <std::string, Menu> menus;

    Language dictionary;                //The selected language
    bool selected_language;             //The check value for the selected language

    std::map
    <std::string, Function> functions;  //A map that stores the functionalities in the store

    product_registry warehouse;         //A class that holds the products in the store
    registry_iter selected_product;     //A pointer to the selected product

    void default_build();
    void change_Menu_build();
    void language_Menu_build();
    void build_default_functions();
    void stock_warehouse();
};

#endif // STORE_H_INCLUDED
