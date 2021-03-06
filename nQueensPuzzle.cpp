#include <stdlib.h>
#include <iostream>
#include "nQueensPuzzle.h"

nQueensPuzzle::nQueensPuzzle(int queens)
{
    noOfQueens = queens;
    queensInRow = new int[noOfQueens];
    noOfSolutions = 0;
}

bool nQueensPuzzle::canPlaceQueen(int k, int i)
{
    for (int j = 0; j < k; j++)
        if ((queensInRow[j] == i)
                || (abs(queensInRow[j] - i) == abs(j-k)))
            return false;
    return true;
}

void nQueensPuzzle::queensConfiguration(int k)
{
    for (int i = 0; i < noOfQueens; i++)
    {
        if (canPlaceQueen(k, i))
        {
            queensInRow[k] = i; //place the kth queen in column i
            if (k == noOfQueens - 1) //all the queens are placed
                printConfiguration(); //print the n-tuple
            else
                queensConfiguration(k + 1); //determine the place
            //for the (k+1)th queen
        }
    }
}

void nQueensPuzzle::printConfiguration()
{
    noOfSolutions++;
    std::cout << "(";
    for (int i = 0; i < noOfQueens - 1; i++)
    std::cout << queensInRow[i] << ", ";
    std::cout << queensInRow[noOfQueens - 1] << ")" << std::endl;

}

int nQueensPuzzle::solutionsCount()
{
    return noOfSolutions;
}

