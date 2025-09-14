#include <iostream>

inline constexpr const int kMaxInt = 2147483647;
inline constexpr const int kMinInt = -2147483648;

using namespace std;

class Array
{
  private:
    int *data = nullptr;
    int size = 0;

  public:
    Array() = default;
    explicit Array(int sizeOfArray) : size(sizeOfArray)
    {
        data = new int[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = 0;
        }
    }
    Array(const Array &other) : size(other.size)
    {
        data = new int[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }
    }
    ~Array() { delete[] data; }
    Array &operator=(const Array &other)
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

int getNumber(const char *msg)
{
    int num = 0;

    std::cout << msg;

    while (true)
    {
        if (std::cin.peek() == '\n' || std::cin.peek() == ' ' || std::cin.fail())
        {
            std::cin.clear();
            while (std::cin.get() != '\n' && !std::cin.eof()) {
                }
            std::cout << "\nError, invalid input. Please try again: ";
            continue;
        }
        if ((std::cin >> num).good() && std::cin.get() == '\n' && (kMinInt <= num) && (num <= kMaxInt))
        {
            return num;
        }
    }
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
        std ::cout << "Element " << i + 1 << ">> ";
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

void showMainMenu()
{
    cout << "\n=== ARRAY OPERATIONS MENU ===" << "\n";
    cout << "1. Work with Array 1" << "\n";
    cout << "2. Work with Array 2" << "\n";
    cout << "3. Perform intersection (Array1 & Array2)" << "\n";
    cout << "4. Show both arrays" << "\n";
    cout << "0. Exit" << "\n";
    cout << "Choose option: ";
}

void showArrayMenu(const char *arrayName)
{
    cout << "\n=== " << arrayName << " OPERATIONS ===" << "\n";
    cout << "1. Input " << arrayName << "\n";
    cout << "2. Show " << arrayName << "\n";
    cout << "3. Clear " << arrayName << "\n";
    cout << "0. Back to main menu" << "\n";
    cout << "Choose option: ";
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
                        cout << "Array 1 cleared" << "\n";
                        break;
                    case 0:
                        break;
                    default:
                        cout << "Invalid choice!" << "\n";
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
                        cout << "Array 2 cleared" << "\n";
                        break;
                    case 0:
                        break;
                    default:
                        cout << "Invalid choice!" << "\n";
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
                cout << "Exiting program..." << "\n";
                break;

            default:
                cout << "Invalid choice! Please try again." << "\n";
        }
    } while (choice != 0);
}

void handleMainMenu()
{
    Array arr1;
    Array arr2;
    handleArrayOperations(arr1, arr2);
}

int main()
{
    handleMainMenu();
    return 0;
}