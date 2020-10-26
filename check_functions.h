#ifndef CHECK_FUNCTIONS_H_INCLUDED
#define CHECK_FUNCTIONS_H_INCLUDED

#include<string>
#include<iostream>

template <class N>
bool check_positive(N num)
{
    return (num >= 0);
}


bool compare_string_nocase(std::string, std::string);
bool check_decision(std::istream&, char);
bool check_word(const std::string&);


std::string input_name(std::istream&);
std::string arrange_input_name(const std::string&);
std::string str_lower(std::string&);
double input_quantity_price(std::istream&);

#endif // CHECK_FUNCTIONS_H_INCLUDED
