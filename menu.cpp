#include "menu.h"
#include "store.h"
#include <limits>


//Access the Menu
void Menu::access(Store& store, std::istream& in, std::ostream& os)
{
    write_options(os);
    os << "\n" << store.phrase("enter");
    (*menuOptions[select_option(store, in, os)-1]).access(store, in, os);       //dereferenced because menuOptions is vector<Function*>
}


//Define the members of Menu
void Menu::make(std::string make_name, vector_fptr make_functions)
{
    menuName = make_name;
    menuOptions = make_functions;
}


//Write out the Menu headline
void Menu::headline(std::ostream& os)
{
    os << "\n\n"
       << "*** Menu " << name() << " ***"
       << "\n\n";
}


//Write out the options in the Menu
void Menu::write_options(std::ostream& os)
{
    headline(os);
    int optionNum = 1;
    typedef std::vector<Function*>::const_iterator iter_F;
    for(iter_F iter = menuOptions.begin();
        iter != menuOptions.end();
        ++iter)
        os << optionNum++ << "  " << (*(*iter)).name() << "\n";     //double dereference because *iter is Function*
}


//Select the number of the option from the Menu
std::vector<Function*>::size_type Menu::select_option(Store& store, std::istream& in, std::ostream& os)
{
    typedef vector_fptr::size_type size_T;
    size_T select, limit;
    limit = menuOptions.size();

    if (in >> select)
    {
        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if((select <= limit) && (select > 0))
            return select;
        else
        {
            os << store.phrase("num_outside_range") << limit << "\n";
            return select_option(store, in, os);
        }
    }
    else
    {
        os << store.phrase("not_num") << "\n";
        in.clear();
        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return select_option(store, in, os);
    }
}
