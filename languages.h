#ifndef LANGUAGES_H_INCLUDED
#define LANGUAGES_H_INCLUDED

#include <string>
#include <map>

class Language      //Class that holds a dictionary with the phrases required in the store
{
public:
    typedef std::map<std::string, std::string> word_map;

    std::string name() const { return languageName; }

    word_map dictionary() const
    {
        return languageDictionary;
    }

    std::string phrase(const std::string& key) const
    {
        word_map::const_iterator iter =
            languageDictionary.find(key);
        if(iter != languageDictionary.end())
            return iter->second;
        else
            return "No phrase in dictionary";
    }

    void load(const std::string& load_name,
              const word_map& load_dictionary)
    {
        languageName = load_name;
        languageDictionary = load_dictionary;
    }

    void load(const Language& load_language)
    {
        languageName = load_language.name();
        languageDictionary = load_language.dictionary();
    }
private:
    std::string languageName;
    word_map languageDictionary;
};


Language croatian();
Language english();
Language not_set();


#endif // LANGUAGES_H_INCLUDED
