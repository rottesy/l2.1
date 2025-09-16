#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

class Array
{
private:
    int *data = nullptr;
    int size = 0;

public:
    Array() = default;
    explicit Array(int sizeOfArray);
    Array(const Array &other);
    ~Array();
    Array &operator=(const Array &other);

    friend Array operator&(const Array &lhs, const Array &rhs);
    friend void input(Array &arr, const char *msg);
    friend void show(const Array &arr, const char *msg);
};

#endif

