#ifndef PRODUCE_H_INCLUDED
#define PRODUCE_H_INCLUDED

#include <string>
#include <iostream>

class Produce       //A class that holds the information of a product
{
public:
    Produce(): produceQuantity(0), producePrice(0) {}
    Produce(const std::string& n, double q, double p):
        produceName(n), produceQuantity(q), producePrice(p) {}

    std::string name() const { return produceName; }
    double quantity() const { return produceQuantity; }
    double price() const { return producePrice; }

    void define(const std::string&, double, double);
    void status(std::ostream&) const;

    void change_name(const std::string&);
    void change_quantity(double quantity);
    void change_price(double price);

private:
    std::string produceName;
    double produceQuantity;
    double producePrice;
};

#endif // PRODUCE_H_INCLUDED
