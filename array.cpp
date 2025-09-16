#include "array.hpp"
#include "const.hpp"
#include "utils.hpp"
#include <iostream>


Array::Array(int sizeOfArray) : size(sizeOfArray)
{
    data = new int[size];
    for (int i = 0; i < size; i++)
    {
        data[i] = 0;
    }
}

Array::Array(const Array &other) : size(other.size)
{
    data = new int[size];
    for (int i = 0; i < size; i++)
    {
        data[i] = other.data[i];
    }
}

Array::~Array() { delete[] data; }

Array &Array::operator=(const Array &other)
{
    if (&other != this)
    {
        delete[] data;
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }
    }
    return *this;
}

Array operator&(const Array &lhs, const Array &rhs)
{
    Array result;
    int count = 0;

    if (lhs.size == 0 || rhs.size == 0)
    {
        return result;
    }

    auto *used = new bool[rhs.size];
    for (int i = 0; i < rhs.size; i++)
    {
        used[i] = false;
    }
    for (int i = 0; i < lhs.size; i++)
    {
        for (int j = 0; j < rhs.size; j++)
        {
            if (lhs.data[i] == rhs.data[j] && !used[j])
            {
                count++;
                used[j] = true;
                break;
            }
        }
    }
    result.data = new int[count];
    result.size = count;

    int index = 0;

    for (int i = 0; i < rhs.size; i++)
    {
        if (used[i])
        {
            result.data[index++] = rhs.data[i];
        }
    }
    delete[] used;
    return result;
}

void input(Array &arr, const char *msg)
{
    while (true)
    {
        arr.size = getNumber("Please enter array size: ");
        if (arr.size <= 0)
        {
            std::cout << "Error, size < 0, please try again." << "\n";
        }
        else
        {
            break;
        }
    }

    std::cout << msg;

    arr.data = new int[arr.size];

    for (int i = 0; i < arr.size; i++)
    {
        std::cout << "Element " << i + 1 << ">> ";
        arr.data[i] = getNumber("");
    }
}

void show(const Array &arr, const char *msg)
{
    std::cout << msg;

    for (int i = 0; i < arr.size; i++)
    {
        std::cout << arr.data[i] << " ";
    }

    std::cout << "\n";
}