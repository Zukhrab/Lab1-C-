#ifndef LAB1
#define LAB1
#include <iostream>

namespace lab1
{
    struct line
    {
        int size;              // number of digits per line
        int* element;
        int* position;
    };

    struct matrix
    {
        int m, n;              // number of lines and n-lines
        line* Line;
    };

    template <class T>
    int getInt(T& a)
    {
        std::cin >> a;
        if (!std::cin.good())
            return -1;

        return 1;
    }

    template <class T>
    T* getCapacity(T* a, int n)
    {
        T* b = new T[n + 1];
        T* tmp = b;
        for (int i = 0; i < n; i++)
            tmp[i] = a[i];

        delete[] a;
        return b;
    }

    void input(matrix& _mt);
    void output(const char* msg, matrix& _mt);
    void erase(matrix& _mt);
    void modified(matrix& _mt1, matrix& _mt2);
    int maxInLine(int* line, int lineSize);
    int maximum(int* arr, int size);
}

#endif