#include "store.h"
#include "functionality.h"
#include "menu.h"
#include "produce.h"
#include "languages.h"
#include "build_functions.h"


using std::istream;
using std::ostream;
using std::string;


//Access the store
void Store::access(istream& in, ostream& os)
{
    access_Menu("language menu", in, os);
}


//Set the language of the store and then build out the store
void Store::set_language(const Language& language)
{
    dictionary = language;
    selected_language = true;
    default_build();
}


//Function to build the default version of the store
void Store::default_build()
{
    build_default_functions();

    menus["main menu"] = build_mainMenu(*this);
    menus["manage menu"] = build_manageMenu(*this);
    menus["query menu"] = build_queryMenu(*this);
    menus["buy menu"] = build_buyMenu(*this);

    change_Menu_build();
}


//Functionalities built into the store pre language selection
void Store::pre_build()
{
    functions["croatian"] = Function("Hrvatski", &set_croatian_language);
    functions["english"] = Function("English", &set_english_language);
    functions["exit"] = Function(dictionary.phrase("exit"), &exit);

    menus["language menu"] = Menu("Languages", {get_function_pointer("croatian"), get_function_pointer("english"), get_function_pointer("exit")});
}


//Build the default functions into the store
void Store::build_default_functions()
{
    functions["access manage"] = Function(dictionary.phrase("manage"), &access_manage);
    functions["access query"] = Function(dictionary.phrase("query"), &access_query);
    functions["access buy"] = Function(dictionary.phrase("buy"), &access_buy);
    functions["access language"] = Function(dictionary.phrase("languages"), &access_language);

    functions["remove"] = Function(dictionary.phrase("remove"), &remove_p);
    functions["add"] = Function(dictionary.phrase("add"), &add);
    functions["change"] = Function(dictionary.phrase("change"), &change);
    functions["return"] = Function(dictionary.phrase("return"), &go_back);
    functions["query"] = Function(dictionary.phrase("query"), &query);
    functions["status"] = Function(dictionary.phrase("status"), &status);
    functions["buy"] = Function(dictionary.phrase("buy"), &buy);

    functions["exit"] = Function(dictionary.phrase("exit"), &exit);
}

//Build the menu for changing a product
void Store::change_Menu_build()
{
    functions["change name"] =
        Function(dictionary.phrase("change") + " " + dictionary.phrase("name"), &change_p_name);
    functions["change quantity"] =
        Function(dictionary.phrase("change") + " " + dictionary.phrase("quantity"), &change_p_quantity);
    functions["change price"] =
        Function(dictionary.phrase("change") + " " + dictionary.phrase("price"), &change_p_price);

    menus["change menu"] = build_changeMenu(*this);
}


void Store::language_Menu_build()
{
    menus["language menu"] = build_languageMenu(*this);
}


//Function to populate the store warehouse with some products
void Store::stock_warehouse()
{
    warehouse.push_back(Produce("jabuka", 100, 10.5));
    warehouse.push_back(Produce("naranca", 80, 7));
    warehouse.push_back(Produce("banana", 57, 3));
    warehouse.push_back(Produce("jagoda", 34, 4.5));
    warehouse.push_back(Produce("borovnica", 120, 12.3));

    deselect_product();
}


//Check if there is a product under that name in the store, if so set selected product to that product
bool Store::check_for_product(const std::string& product)
{
    registry_iter iter = warehouse.begin();

    while (iter != warehouse.end())
        if(product == (*iter).name())
        {
            select_product(iter);
            return true;
        }
        else
            ++iter;
    return false;
}


//Add a new product to the store
void Store::add_product(const Produce& product)
{
    warehouse.push_back(product);
}


//Remove the selected product from the store
void Store::remove_product()
{
    warehouse.erase(selected_product);
    deselect_product();
}


//Buy the product
void Store::buy_product(double quantity)
{
    double remaining = (*selected_product).quantity() - quantity;
    if (remaining == 0)
        remove_product();
    else
        change_product_quantity(remaining);
}


//Write out the name, quantity and price of the selected product
void Store::product_status(ostream& os) const
{
    os << "\n"
       << "  - " << phrase("name") << ": " << (*selected_product).name() << "\n"
       << "  - " << phrase("quantity") << ": " << (*selected_product).quantity() << "\n"
       << "  - " << phrase("price") << ": " << (*selected_product).price() << "\n";
}


//Write out status of all the products in the warehouse
void Store::warehouse_status(std::ostream& os)
{
    selected_product = warehouse.begin();
    while(check_selected())
    {
        product_status(os);
        selected_product++;
    }
}


//Write out the names of the products in the warehouse
void Store::show_wares(ostream& os)
{
    selected_product = warehouse.begin();
    int count = 1;
    while(check_selected())
    {
        os << " " << count++ << " "
           << (*selected_product).name() << "\n";
        selected_product++;
    }
}


//Change the name of the selected product
void Store::change_product_name(const string& new_name)
{
    (*selected_product).change_name(new_name);
}


//Change the quantity of the selected product
void Store::change_product_quantity(double new_quantity)
{
    (*selected_product).change_quantity(new_quantity);
}


//Change the price of the selected product
void Store::change_product_price(double new_price)
{
    (*selected_product).change_price(new_price);
}
