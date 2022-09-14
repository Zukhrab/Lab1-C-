#include "lab1.h"

using namespace std;
namespace lab1
{
    matrix* input(matrix* _mt)
    {
        const char* emessage = "";
        int m, n;                       // number lines and columns

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

        for (int i = 0; i < m; i++)
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
                    _mt->Line[i].element = getCapacity(_mt->Line[i].element, k);
                    _mt->Line[i].position = getCapacity(_mt->Line[i].position, k);
                    _mt->Line[i].element[k] = a;
                    _mt->Line[i].position[k] = j;
                    k++;
                }
            }
            _mt->Line[i].size = k;
        }

        return _mt;
    }

    matrix* modified(matrix* _mt1, matrix* _mt2)
    {
        int i;
        int count, lineNum = 0;
        int resNumberIndex, reply = 0;

        int* arr = new int[_mt1->m];
        
        for (count = 0; count < _mt1->m; count++)
            for (i = 0; i < _mt1->Line[count].size; i++)
            {
                resNumberIndex = maxInLine(_mt1->Line[count].element, _mt1->Line[count].size);
                arr[count] = _mt1->Line[count].element[resNumberIndex];
            }

        try
        {
            _mt2->Line = new line[_mt1->m];
        }
        catch (bad_alloc& ba)
        {
            cout << "Too many rows !" << ba.what() << endl;
            erase(_mt2);

            return nullptr;
        }

        _mt2->Line->element = arr;
        _mt2->Line->position = nullptr;
        _mt2->Line->size = _mt1->m;
        _mt2->m = 1;
        _mt2->n = _mt1->m;

        return _mt2;
    }

    void output(const char* msg, matrix* _mt)
    {
        int count;
        int i, j = 0;
       
        cout << endl << msg << endl;
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
            if (arr[i] > max)
                max = arr[i];

        return max;
    }

    int maxInLine(int* line, int lineSize)
    {
        int i, j, result;
        int reply = 0;

        int* massive = new int[lineSize];

        for (i = 0; i < lineSize; i++)
        {
            for (j = 0; j < lineSize; j++)
                if (line[i] == line[j])
                    reply++;

            massive[i] = reply;
            reply = 0;
        }
        result = maximum(massive, lineSize);
        
        i = 0;
        while (result != massive[i])
            i++;

        result = i;

        return result;
    }
}