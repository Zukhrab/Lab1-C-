#include "lab1.h"

namespace lab1
{
    matrix* input(matrix* _mt)
    {
        const char* emessage = "";
        int m, n;
        int i = 0, j;
        int p;

        do
        {
            cout << emessage << endl;
            cout << "Enter number of lines" << endl;

            emessage = "Error, repeat !";
            if (getInt(m) < 1)
                return nullptr;

            cout << "Enter number of columns" << endl;
            if (getInt(n) < 1)
                return nullptr;
        } while (m < 1);

        _mt->m = m;
        _mt->n = n;

        try
        {
            _mt->Line = new line[m];
        }
        catch (bad_alloc& ba)
        {
            cout << "Too many rows !" << ba.what() << endl;
            erase(_mt);

            return nullptr;
        }

        /*for (; i < m; i++)
        {
            emessage = "";

            do
            {
                cout << emessage << endl;
                cout << "Enter number of elements in line ¹" << (i + 1) << "-- ";

                emessage = "Error, repeat !";

            }
        }*/


    }

    void erase(matrix* _mt)
    {
        for (int i = 0; i < _mt->m; i++)
            delete[] _mt->Line[i].number;

        delete _mt->Line;
    }

}