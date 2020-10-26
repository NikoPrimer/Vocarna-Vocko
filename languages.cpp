#include "languages.h"

using std::string;
using std::map;


//Croatian language dictionary
Language croatian()
{
    Language ret;

    string name = "Hrvatski";

    map<string, string> dictionary;

    dictionary["exit"] = "Izlaz";
    dictionary["store_exit"] = "Izasli ste iz ducana";
    dictionary["enter"] = "Molim vas unesite broj opcije: ";
    dictionary["store"] = "Vocarna";

    dictionary["language_set"] = "Odabrali ste hrvatski jezik";

    dictionary["num_outside_range"] = "Molim vas, unesite broj izmedju 1 i ";
    dictionary["not_num"] = "Molim vas unesite broj";
    dictionary["not_positive_num"] = "Molim vas unesite broj veci ili jednak 0";
    dictionary["no_input"] = "Niste ništa unijeli";
    dictionary["not_word"] = "Molim vas unosite samo slova";
    dictionary["quit_?"] = "Unesite Q ili q ako se zelite vratiti na izbornik, bilo sto drugo da ponovite operaciju: ";
    dictionary["decision"] = "Unesite Y ili y da potvrdite: ";

    dictionary["manage"] = "Upravljanje";
    dictionary["query"] = "Upit";
    dictionary["buy"] = "Kupovina";
    dictionary["languages"] = "Jezici";
    dictionary["status"] = "Stanje";
    dictionary["add"] = "Dodavanje";
    dictionary["remove"] = "Brisanje";
    dictionary["change"] = "Izmjena";
    dictionary["return"] = "Povratak";


    dictionary["enter_product"] = "Molim vas, upisite ime artikla: ";
    dictionary["no_product"] = "Zao mi je ali nemamo taj artikal na skladistu";

    dictionary["erase_?"] = "Zelite izbrisati proizvod ";
    dictionary["erase_cancel"] = "Odlucili ste ne izbrisati artikal ";
    dictionary["erase_true"] = "Izbrisali ste artikal ";

    dictionary["product_in"] = " postoji na skladistu";

    dictionary["add_?"] = "Zelite li dodati jos ";
    dictionary["added"] = "Dodali ste artikal";

    dictionary["change_?"] = "Sto zelite izmjeniti na proizvodu?";
    dictionary["not_enough_q"] = "Nema dovoljno kolicine na skladistu";
    dictionary["buy_?"] = "Zelite li kupiti ";

    dictionary["set_name"] = "Odredite naziv: ";
    dictionary["set_quantity"] = "Odredite kolicinu [kg]: ";
    dictionary["set_price"] = "Odredite cijenu [kn]: ";

    dictionary["product"] = "Artikal";
    dictionary["name"] = "Naziv";
    dictionary["quantity"] = "Kolicina [kg]";
    dictionary["price"] = "Cijena [kn]";

    dictionary["bought"] = "Kupili ste ";

    ret.load(name, dictionary);

    return ret;
}


//Croatian language dictionary
Language english()
{
    Language ret;

    string name = "English";

    map<string, string> dictionary;

    dictionary["exit"] = "Exit";
    dictionary["store_exit"] = "You exit the store";
    dictionary["enter"] = "Please enter the number of an option: ";
    dictionary["store"] = "Fruit Store";

    dictionary["language_set"] = "You chose english";

    dictionary["num_outside_range"] = "Please enter a number between 1 and ";
    dictionary["not_num"] = "Please enter a number";
    dictionary["not_positive_num"] = "Please enter a number greater than 0";
    dictionary["no_input"] = "No input";
    dictionary["not_word"] = "Please enter only letters";
    dictionary["quit_?"] = "Enter Q or q to exit, anything else to repeat the operation: ";
    dictionary["decision"] = "Enter Y or y to confirm: ";

    dictionary["manage"] = "Manage";
    dictionary["query"] = "Query";
    dictionary["buy"] = "Buy";
    dictionary["languages"] = "Languages";
    dictionary["status"] = "Status";
    dictionary["add"] = "Add";
    dictionary["remove"] = "Erase";
    dictionary["change"] = "Change";
    dictionary["return"] = "Return";


    dictionary["enter_product"] = "Please neter the name of the product: ";
    dictionary["no_product"] = "Im sorry but we don't have that product";

    dictionary["erase_?"] = "You want to erase the product: ";
    dictionary["erase_cancel"] = "You decided not to erase the porduct:  ";
    dictionary["erase_true"] = "You erased the product: ";

    dictionary["product_in"] = " is in the store";

    dictionary["add_?"] = "Do you want to add more: ";
    dictionary["added"] = "You added the product: ";

    dictionary["change_?"] = "What do you want to change?";
    dictionary["not_enough_q"] = "Not enough product quantity";
    dictionary["buy_?"] = "Do you want to buy ";

    dictionary["set_name"] = "Enter name: ";
    dictionary["set_quantity"] = "Enter quantity [kg]: ";
    dictionary["set_price"] = "Enter price [kn]: ";

    dictionary["product"] = "Product";
    dictionary["name"] = "Name";
    dictionary["quantity"] = "Quantity [kg]";
    dictionary["price"] = "Price [kn]";

    dictionary["bought"] = "You bought ";

    ret.load(name, dictionary);

    return ret;
}


//Dictionary to load before the language is selected
Language not_set()
{
    Language ret;

    string name = "Not Set";

    map<string, string> dictionary;
    dictionary["exit"] = "Exit";
    dictionary["num_outside_range"] = "Please enter a number between 1 and ";
    dictionary["not_num"] = "Please enter a number";
    dictionary["store_exit"] = "You exit the store";
    dictionary["enter"] = "Please enter the option number: ";

    ret.load(name, dictionary);

    return ret;
}
