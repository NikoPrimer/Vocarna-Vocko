#include <cctype>
#include <string>
#include <stdexcept>
#include <limits>
#include <iostream>
#include <vector>
#include "check_functions.h"
#include "split_t.h"

using std::string;
using std::isalpha;
using std::domain_error;
using std::tolower;
using std::istream;
using std::ostream;
using std::vector;


//Convert string to all lower case characters
string str_lower(string& ret)
{
    for(string::iterator i = ret.begin();
        i != ret.end();
        ++i)
    {
        if(isalpha(*i))
            *i = tolower(*i);
        else
            throw domain_error("Not a letter");
    }
    return ret;
}


//Compare two strings regardless of upper or lower case characters
bool compare_str_nocase(string s1, string s2)
{
    return (str_lower(s1) == str_lower(s2));
}


//Check if user wants to go through with operation
bool check_decision(istream& in, char q)
{
    in.clear();
    char c;
    in.get(c);
    if(c == '\n')
    {
        return false;
    }

    if(tolower(c) == q)
    {
        in.get(c);
        if(c == '\n')
        {
            return true;
        }
        else
        {
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return false;
        }
    }
    else
    {
        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
}


//Check if string contains only letters
bool check_word(const std::string& word)
{
    for(string::const_iterator iter = word.begin();
        iter != word.end();
        ++iter)
        if(!isalpha(*iter))
            throw domain_error("Not a letter");
    return true;
}


//Take in input and return a string that is comparable to the Produce::name()
string input_name(istream& in)
{
    in.clear();
    string input;
    getline(in, input);
    if (input.empty())
        throw domain_error("No input");
    else
    {
        string ret = arrange_input_name(input);
        return ret;
    }
}


//Take in a string, check for viable words and remove extra whitespace
string arrange_input_name(const string& input)
{
    vector<string> words;
    split_t(input, back_inserter(words));
    vector<string>::iterator iter = words.begin();
    string ret;
    if (check_word(*iter))
        ret = str_lower(*iter++);

    while(iter != words.end())
    {
        ret += " ";
        if (check_word(*iter))
            ret += str_lower(*iter++);
    }
    return ret;
}


//Take in input an return double that is valid for Produce::quantity or Produce::price
double input_quantity_price(istream& in)
{
    double input;
    in.clear();
    if (in >> input)
    {
        if(check_positive(input))
        {
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return input;
        }
        else
        {
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw domain_error("Not a positive number");
        }
    }
    else
    {
        in.clear();
        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw domain_error("Not a number");
    }
}
