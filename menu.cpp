#include "menu.hpp"
#include "utils.hpp"
#include <iostream>

void showMainMenu()
{
    std::cout << "\n=== ARRAY OPERATIONS MENU ===" << "\n";
    std::cout << "1. Work with Array 1" << "\n";
    std::cout << "2. Work with Array 2" << "\n";
    std::cout << "3. Perform intersection (Array1 & Array2)" << "\n";
    std::cout << "4. Show both arrays" << "\n";
    std::cout << "0. Exit" << "\n";
    std::cout << "Choose option: ";
}

void showArrayMenu(const char *arrayName)
{
    std::cout << "\n=== " << arrayName << " OPERATIONS ===" << "\n";
    std::cout << "1. Input " << arrayName << "\n";
    std::cout << "2. Show " << arrayName << "\n";
    std::cout << "3. Clear " << arrayName << "\n";
    std::cout << "0. Back to main menu" << "\n";
    std::cout << "Choose option: ";
}

void handleArrayOperations(Array &arr1, Array &arr2)
{
    int choice;

    do
    {
        showMainMenu();
        choice = getNumber("");

        switch (choice)
        {
            case 1:
                showArrayMenu("ARRAY 1");
                switch (getNumber(""))
                {
                    case 1:
                        input(arr1, "Enter Array 1 elements:\n");
                        break;
                    case 2:
                        show(arr1, "Array 1: ");
                        break;
                    case 3:
                        arr1 = Array();
                        std::cout << "Array 1 cleared" << "\n";
                        break;
                    case 0:
                        break;
                    default:
                        std::cout << "Invalid choice!" << "\n";
                }
                break;

            case 2:
                showArrayMenu("ARRAY 2");
                switch (getNumber(""))
                {
                    case 1:
                        input(arr2, "Enter Array 2 elements:\n");
                        break;
                    case 2:
                        show(arr2, "Array 2: ");
                        break;
                    case 3:
                        arr2 = Array();
                        std::cout << "Array 2 cleared" << "\n";
                        break;
                    case 0:
                        break;
                    default:
                        std::cout << "Invalid choice!" << "\n";
                }
                break;

            case 3:
            {
                Array result = arr1 & arr2;
                show(result, "Intersection result: ");
                break;
            }

            case 4:
                show(arr1, "Array 1: ");
                show(arr2, "Array 2: ");
                break;

            case 0:
                std::cout << "Exiting program..." << "\n";
                break;

            default:
                std::cout << "Invalid choice! Please try again." << "\n";
        }
    } while (choice != 0);
}

void handleMainMenu()
{
    Array arr1;
    Array arr2;
    handleArrayOperations(arr1, arr2);
}