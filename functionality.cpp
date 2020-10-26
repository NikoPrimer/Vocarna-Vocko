#include "store.h"
#include "produce.h"
#include "check_functions.h"
#include <stdexcept>
#include <string>


using std::istream;
using std::ostream;
using std::list;
using std::domain_error;
using std::string;


//Set the croatian language in store
void set_croatian_language(Store& store, istream& in, ostream& os)
{
    store.set_language(croatian());
    os << "\n" << store.phrase("language_set") << "\n";
}


//Set the english language in store
void set_english_language(Store& store, istream& in, ostream& os)
{
    store.set_language(english());
    os << "\n" << store.phrase("language_set") << "\n";
}


//Take in a name for a product and remove it from the store if it is there
void remove_p(Store& store, istream& in, ostream& os)
{
    os << store.headline(store.phrase("remove")) << "\n";

    store.show_wares(os);

    os << "\n" << store.phrase("enter_product");

    try
    {
        string product = input_name(in);
        if (!store.check_for_product(product))
        {
            os << "\n" << store.phrase("no_product") << "\n";
        }
        else
        {
            os << "\n" << store.phrase("erase_?") << product << "\n"
               << "\n" << store.phrase("decision");
            if (check_decision(in, 'y'))
            {
                store.remove_product();
                os << "\n" << store.phrase("erase_true") << product << "\n";
            }
            else
                os << "\n" << store.phrase("erase_cancel") << product << "\n";
        }
    }
    catch(const domain_error& e)
    {
        os << e.what() <<"\n";
    }
    if(store.check_selected())
            store.deselect_product();

    os << "\n" << store.phrase("quit_?");
    if(!check_decision(in, 'q'))
        remove_p(store, in, os);
    else
        go_back(store, in, os);
}


//Add a product to the store
void add(Store& store, istream& in, ostream& os)
{
    os << store.headline(store.phrase("add"))
       << store.phrase("enter_product");

    try
    {
        string product = input_name(in);
        if (store.check_for_product(product))
        {
            os << "\n"
               << product << store.phrase("product_in") << "\n";

            store.product_status(os);

            os << "\n" << store.phrase("add_?") << product << "?"
               << "\n\n" << store.phrase("decision");
            if (check_decision(in, 'y'))
            {
                os << "\n" << store.phrase("set_quantity");
                double added = input_quantity_price(in);
                store.change_product_quantity(added + store.product_quantity());
                store.product_status(os);
            }
            else
            {
                store.deselect_product();
            }
        }
        else
        {
            os << store.phrase("set_quantity");
            double quantity = input_quantity_price(in);

            os << store.phrase("set_price");
            double price = input_quantity_price(in);

            Produce new_product(product, quantity, price);
            store.add_product(new_product);
            store.select_new_product();
            os << "\n" << store.phrase("added");
            store.product_status(os);
        }
    }
    catch(const domain_error& e)
    {
        os << "\n" << e.what() << "\n";
    }
    if(store.check_selected())
            store.deselect_product();

    os << "\n" << store.phrase("quit_?");
    if(!check_decision(in, 'q'))
        add(store, in, os);
    else
        go_back(store, in, os);
}


//Change a characteristic of a product in the store
void change(Store& store, istream& in, ostream& os)
{
    os << store.headline(store.phrase("change")) << "\n";

    store.show_wares(os);

    os << "\n";

    try
    {
        if(store.check_selected())
        {
            store.product_status(os);
            os << store.phrase("change_?") << "\n";
            store.access_Menu("change menu", in, os);
        }
        else
        {
            os << store.phrase("enter_product");
            string product = input_name(in);
            if (store.check_for_product(product))
            {
                os << "\n" << product << store.phrase("product_in") << "\n";
                store.access_Menu("change menu", in, os);
            }
            else
            {
                os << "\n" << store.phrase("no_product") << "\n";
            }
        }

    }
    catch(const domain_error& e)
    {
        os << "\n" << e.what() << "\n";
    }
    if(store.check_selected())
            store.deselect_product();

    os << "\n" << store.phrase("quit_?");
    if(!check_decision(in, 'q'))
        change(store, in, os);
    else
        go_back(store, in, os);
}


//Exit from the store
void exit(Store& store, istream& in, ostream& os)
{
    os << "\n" << store.phrase("store_exit") << "\n";
}


//Go to the main menu
void go_back(Store& store, istream& in, ostream& os)
{
    if (store.check_selected())
        store.deselect_product();
    store.access(in, os);
}


//Show the status of the selected product
void query(Store& store, istream& in, ostream& os)
{
    os << store.headline(store.phrase("query"))
       << store.phrase("enter_product");

    try
    {
        string product = input_name(in);
        if (store.check_for_product(product))
        {
            os << "\n" << product << store.phrase("product_in") << "\n";
            store.product_status(os);
        }
        else
        {
            os << "\n" << store.phrase("no_product") << "\n";
        }
    }
    catch(const domain_error& e)
    {
        os << "\n" << e.what() << "\n";
    }
    if(store.check_selected())
            store.deselect_product();

    os << "\n" << store.phrase("quit_?");
    if(!check_decision(in, 'q'))
    {
        query(store, in, os);
    }
    else
    {
        go_back(store, in, os);
    }
}


void status(Store& store, istream& in, ostream& os)
{
    os << store.headline(store.phrase("status"));

    store.warehouse_status(os);

    os << "\n" << store.phrase("quit_?");
    if(!check_decision(in, 'q'))
        status(store, in, os);
    else
        go_back(store, in, os);
}


void buy(Store& store, istream& in, ostream& os)
{
    os << store.headline(store.phrase("buy")) << "\n";

    store.show_wares(os);

    os << "\n" << store.phrase("enter_product");

    try
    {
        string product = input_name(in);
        if (!store.check_for_product(product))
        {
            os << "\n" << store.phrase("no_product") << "\n";
        }
        else
        {
            store.product_status(os);
            os << "\n" << store.phrase("set_quantity");
            double quantity = input_quantity_price(in);
            if(quantity <= store.product_quantity())
            {
                store.buy_product(quantity);
                os << "\n" << store.phrase("bought") << quantity
                   << " kg " << store.product_name() << "\n";
                store.product_status(os);
            }
            else
            {
                quantity = store.product_quantity();
                os << "\n" << store.phrase("not_enough_q") << "\n\n"
                   << store.phrase("buy_?") << quantity << "\n\n"
                   << store.phrase("decision");
                if(check_decision(in, 'y'))
                {
                    store.buy_product(store.product_quantity());
                    os << "\n" << store.phrase("bought") << quantity
                       << " kg " << product;
                }
            }
        }
    }
    catch(const domain_error& e)
    {
        os << "\n" << e.what() << "\n";
    }
    if(store.check_selected())
            store.deselect_product();

    os << "\n" << store.phrase("quit_?");
    if(!check_decision(in, 'q'))
        buy(store, in, os);
    else
        go_back(store, in, os);
}


//Change the name of a product in the store
void change_p_name(Store& store, istream& in, ostream& os)
{
    os << store.phrase("set_name");
    try
    {
        string new_name = input_name(in);
        store.change_product_name(new_name);
        store.product_status(os);
    }
    catch(const domain_error& e)
    {
        os << e.what() <<"\n";
    }
}


//Change the quantity of a product in the store
void change_p_quantity(Store& store, istream& in, ostream& os)
{
    os << store.phrase("set_quantity");
    try
    {
        double new_quantity = input_quantity_price(in);
        store.change_product_quantity(new_quantity);
        store.product_status(os);
    }
    catch(const domain_error& e)
    {
        os << "\n" << e.what() <<"\n";
    }
}


//Change the price of a product in the store
void change_p_price(Store& store, istream& in, ostream& os)
{
    os << store.phrase("set_price");
    try
    {
        double new_price = input_quantity_price(in);
        store.change_product_price(new_price);
        store.product_status(os);
    }
    catch(const domain_error& e)
    {
        os << "\n" << e.what() <<"\n";
    }
}


//Access the Manage Menu
void access_manage(Store& store, istream& in, ostream& os)
{
    store.access_Menu("manage menu", in, os);
}


//Access the Query Menu
void access_query(Store& store, istream& in, ostream& os)
{
    store.access_Menu("query menu", in, os);
}


//Access the Buy Menu
void access_buy(Store& store, istream& in, ostream& os)
{
    store.access_Menu("buy menu", in, os);
}


//Access the Language Menu
void access_language(Store& store, istream& in, ostream& os)
{
    store.access_Menu("language menu", in, os);
}









