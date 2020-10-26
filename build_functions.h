#ifndef BUILD_FUNCTIONS_H_INCLUDED
#define BUILD_FUNCTIONS_H_INCLUDED

#include "menu.h"
#include "store.h"

Menu build_mainMenu(Store&);
Menu build_languageMenu(Store&);
Menu build_changeMenu(Store&);
Menu build_manageMenu(Store&);
Menu build_queryMenu(Store&);
Menu build_buyMenu(Store&);

#endif // BUILD_FUNCTIONS_H_INCLUDED
