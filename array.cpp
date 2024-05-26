#include <iostream>

using namespace std;
#define MAXSIZE 9999

class Array {
private:
    int* arr;
    int size;
    int current;
public:
    Array()
    {
        arr = new int[0];
        size = 0;
    }
    bool push(int data)
    {
       int* temp = new int[size + 1];
       for (int i = 0; i < size; i++) 
       {
                temp[i] = arr[i];
       }
       delete[] arr;
       arr = temp;
       arr[size] = data;
       size++;
       if (size < MAXSIZE)
       {
           return true;
       }
       else
       {
           return false;
       }
    }
    void print()
    {
        std::cout << "Now in array " << size <<" elements"<< std::endl;
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        std::cout << "--------------------------------------" << std::endl;
    }
    ~Array() { delete[] arr; }
};

int main()
{
    bool exit = false;
    Array arr;
    while (exit == false)
    {
        arr.print();
        std::cout << "Enter -1 to exit or add elements in array! " << std::endl;
        int data;
        std::cin >> data;
        cout << endl;
        if (data == -1)
        {
            std::cout << "Exited: " << std::endl;
            return 0;
        }
        if (!arr.push(data))
        {
            std::cout << "The maximum size of the array" << std::endl;
            return 0;

        }
    }
    return 0;
}
