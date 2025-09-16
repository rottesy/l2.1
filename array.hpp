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

    friend Array operator&(const Array &lhs, const Array &rhs)
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
    friend void input(Array &arr, const char *msg);
    friend void show(const Array &arr, const char *msg);
};

#endif
