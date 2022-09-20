/*
//
//
// ASAKHANOV ZUKHRAB (AZR)
//
//
*/

#include "lab1.h"
#include <exception>

using namespace std;
using namespace lab1;

int main()
{
    matrix matrix1, matrix2;
    
    matrix1 = { 0, 0, nullptr };
    matrix2 = { 0, 0, nullptr };

    input(matrix1);
    output("Input", matrix1);
    modified(matrix1, matrix2);
    output("Output\n", matrix2);
    erase(matrix1);
    erase(matrix2);

    return 0;
}