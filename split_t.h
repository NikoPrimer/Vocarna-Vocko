#ifndef SPLIT_T_H_INCLUDED
#define SPLIT_T_H_INCLUDED

#include <string>
#include <algorithm>

using std::string;
using std::find;
using std::find_if;
using std::isspace;

bool wspace(char c)
{
    return isspace(c);
}


bool not_wspace(char c)
{
    return !isspace(c);
}


template <class Out>
void split_t (const string& s, Out os)
{
    typedef string::const_iterator iter;

    iter i = s.begin();

    while(i != s.end())
    {
        i = find_if(i, s.end(), not_wspace);

        iter j = find_if(i, s.end(), wspace);

        if (i != s.end())
            *os++ = string(i, j);

        i = j;
    }
}

#endif // SPLIT_T_H_INCLUDED
