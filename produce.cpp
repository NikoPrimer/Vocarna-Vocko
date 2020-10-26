#include "produce.h"

void Produce::define(const std::string& def_name, double def_quantity, double def_price)
{
    produceName = def_name;
    produceQuantity = def_quantity;
    producePrice = def_price;
}


void Produce::status (std::ostream& os) const
{
    os << name() << "\n";
    os << quantity() << " kg\n";
    os << price() << " kn\n";
}


void Produce::change_name(const std::string& new_name)
{
    produceName = new_name;
}


void Produce::change_quantity(double new_quantity)
{
    produceQuantity = new_quantity;
}


void Produce::change_price(double new_price)
{
    producePrice = new_price;
}
