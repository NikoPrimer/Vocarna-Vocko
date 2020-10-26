#include "build_functions.h"
#include <string>
#include <vector>

//Build function for the main menu
Menu build_mainMenu(Store& store)
{
    std::vector<Function*> options;
    options.push_back(store.get_function_pointer("access manage"));
    options.push_back(store.get_function_pointer("access query"));
    options.push_back(store.get_function_pointer("access buy"));
    options.push_back(store.get_function_pointer("exit"));

    return Menu(store.phrase("store"), options);;
}

//Build function for the change product menu
Menu build_changeMenu(Store& store)
{
    std::vector<Function*> options;
    options.push_back(store.get_function_pointer("change name"));
    options.push_back(store.get_function_pointer("change quantity"));
    options.push_back(store.get_function_pointer("change price"));

    return Menu(store.phrase("change") + " " + store.phrase("product"), options);
}


//Build function for the language Menu
Menu build_languageMenu(Store& store)
{
    std::vector<Function*> options;
    options.push_back(store.get_function_pointer("croatian"));
    options.push_back(store.get_function_pointer("english"));
    options.push_back(store.get_function_pointer("return"));

    return Menu(store.phrase("languages"), options);
}


//Build function for the manage product menu
Menu build_manageMenu(Store& store)
{
    std::vector<Function*> options;
    options.push_back(store.get_function_pointer("remove"));
    options.push_back(store.get_function_pointer("add"));
    options.push_back(store.get_function_pointer("change"));
    options.push_back(store.get_function_pointer("status"));
    options.push_back(store.get_function_pointer("return"));


    return Menu(store.phrase("manage"), options);
}


//Build function for the buy product menu
Menu build_buyMenu(Store& store)
{
    std::vector<Function*> options;
    options.push_back(store.get_function_pointer("buy"));
    options.push_back(store.get_function_pointer("return"));


    return Menu(store.phrase("buy"), options);
}


//Build function for the query menu
Menu build_queryMenu(Store& store)
{
    std::vector<Function*> options;
    options.push_back(store.get_function_pointer("query"));
    options.push_back(store.get_function_pointer("return"));


    return Menu(store.phrase("query"), options);
}
