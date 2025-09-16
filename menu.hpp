#ifndef MENU_HPP
#define MENU_HPP

#include "array.hpp"

void showMainMenu();
void showArrayMenu(const char *arrayName);
void handleArrayOperations(Array &arr1, Array &arr2);
void handleMainMenu();

#endif