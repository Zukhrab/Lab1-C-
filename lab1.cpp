#include "lab1.h"

using namespace std;
namespace lab1
{
    matrix* input(matrix* _mt)
    {
        const char* emessage = "";
        int m, n;                       // number lines and columns
        //int i;

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

        for (int i = 0; i < m; )
        {
            try
            {
                _mt->Line[i].element = new int [1];
                _mt->Line[i].position = new int[1];
            }
            catch (bad_alloc& ba)
            {
                cout << "Too many rows !" << ba.what() << endl;
                erase(_mt);

                return nullptr;
            }

            cout << "Enter element for matrix line number " << (i + 1) << " --> " << endl;
            int k = 0;          // for getCapacity()

            for (int j = 0; j < _mt->n; j++)
            {
                int a;
                if (getInt(a) < 1)
                {
                    erase(_mt);
                    return nullptr;
                }
                if (a != 0)
                {
                    _mt->Line->element = getCapacity(_mt->Line[i].element, k);
                    _mt->Line->position = getCapacity(_mt->Line[i].position, k);
                    _mt->Line[i].element[k] = a;
                    _mt->Line[i].position[k] = j;
                    k++;
                }
            }
            _mt->Line[i].size = k;
            i++;
        }

        return _mt;
    }

    /*matrix* modified(matrix* _mt1, matrix* _mt2)
    {
        int count, lineNum = 0;
        int resNumber, reply = 0;
        for (count = 0; _mt1->Line[lineNum].element[count]; count++)
        {
            resNumber = _mt->Line[lineNum].element[count];
            if (resNumber == )
        }
    }*/

    void output(const char* msg, matrix* _mt)
    {
        int count;
        int i, j = 0;
       
        cout << msg << endl;
        for (i = 0; i < _mt->m; i++)
        {
            for (count = 0; count < _mt->Line[i].size; count++)
                cout << _mt->Line[i].element[count] << " ";
            cout << endl;
        }
    }

    void erase(matrix* _mt)
    {
        for (int i = 0; i < _mt->m; i++)
            delete[] _mt->Line[i].element;

        delete[] _mt->Line;
    }

    int maximum(int* arr, int size)
    {
        int max;
        max = arr[0];
        for (int i = 0; i < size; i++)
        {
            if (arr[i] > max)
            {
                max = arr[i];
            }
        }
        return max;
    }

    int maxInLine(int* array)
    {
        int i, j, result;
        int replay = 0;

        int sizeArray = (sizeof  array);
        sizeArray = sizeArray / 4;

        int* massive = new int[sizeArray];

        for (i = 0; i < sizeArray; i++)
        {
            for (j = 0; j < sizeArray; j++)
                if (array[i] == array[j])
                    replay++;
            massive[i] = replay;
            replay = 0;
        }

        result = maximum(massive, sizeArray);

        return result;
    }
}