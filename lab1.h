#ifndef LAB1
#define LAB1

#include <iostream>

using namespace std;
namespace lab1
{
    struct elemPos
    {
        int element;
        int position;
    };

    struct line
    {
        int size;              // number of digits per line
        int* number;        // pushed number in line
        elemPos* array;     // array for non-zero elements
    };

    struct matrix
    {
        int m, n;           // number of lines and n-lines
        line* Line;
    };

    template <class T>
    int getInt(T& a)
    {
        cin >> a;
        if (!cin.good())
            return -1;

        return 1;
    }


    matrix* input(matrix* _mt);
    void output(const char* msg, matrix* _mt);
    void erase(matrix* _mt);
    matrix* modified(matrix* _mt1, matrix* _mt2);
}

#endif