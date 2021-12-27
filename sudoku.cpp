#include "sudoku.h"
#include <iostream>

Sudoku::Sudoku()
{

}
void Sudoku::printSudokuGrid()
{

    for (int i=0 ;i<9;i++) {
    for (int j=0 ;j<9;j++) {

            std::cout<<grid[i][j]<<" ";
            if (j==8) {
                std::cout<<std::endl;
            }
        }
    }
}

bool Sudoku::solveSudoku()
{
    int row, col;
    if (findEmptyGridSlot(row, col))
    {
        for (int num = 1; num <= 9; num++)
        {
            if (canPlaceNum(row, col, num))
            {
                grid[row][col] = num;
                if (solveSudoku()) //recursive call
                    return true;
                grid[row][col] = 0;
            }
        }
        return false; //backtrack
    }
    else
        return true; //there are no empty slots
    //return true;
}

bool Sudoku::findEmptyGridSlot(int &row, int &col)
{
    for (int i=0;i<9;i++) {
        for (int j=0;j<9;j++) {
            if (grid[i][j]==0) {
                row=i;
                col=j;
                return true;
            }
        }
    }
    return  false;
}

bool Sudoku::canPlaceNum(int row, int col, int num)
{
    bool alreadyInBox=false;
    if( row>=0 && row<3){
        if( col>=0 && col<3){
            alreadyInBox=numAlreadyInBox(0,0,num);
        }else if (col>=3 && col<6) {
            alreadyInBox=numAlreadyInBox(0,3,num);
        } else if (col>=6 && col<9) {
            alreadyInBox=numAlreadyInBox(0,6,num);
        }

    }
    if( row>=3 && row<6){
        if( col>=0 && col<3){
            alreadyInBox=numAlreadyInBox(3,0,num);
        }else if (col>=3 && col<6) {
            alreadyInBox=numAlreadyInBox(3,3,num);
        } else if (col>=6 && col<9) {
            alreadyInBox=numAlreadyInBox(3,6,num);
        }

    }
    if( row>=6 && row<9){
        if( col>=0 && col<3){
            alreadyInBox=numAlreadyInBox(6,0,num);
        }else if (col>=3 && col<6) {
            alreadyInBox=numAlreadyInBox(6,3,num);
        } else if (col>=6 && col<9) {
            alreadyInBox=numAlreadyInBox(6,6,num);
        }

    }
    return  !numAlreadyInRow(row,num)&&
            !numAlreadyInCol(col,num)&&
            !alreadyInBox;
}

bool Sudoku::numAlreadyInRow(int row, int num)
{
    for (int j=0;j<9;j++) {
        if (grid[row][j]==num) {
            return  true;
        }
    }
    return  false;
}

bool Sudoku::numAlreadyInCol(int col, int num)
{
    for (int j=0;j<9;j++) {
        if (grid[j][col]==num) {
            return  true;
        }
    }
    return  false;

}

bool Sudoku::numAlreadyInBox(int smallGridRow, int smallGridCol, int num)
{
    for (int i=smallGridRow;i<smallGridRow+3;i++) {
        for (int j=smallGridCol;j<smallGridCol+3;j++) {

            if (grid[i][j]==num) {
                return true;
            }
        }
    }

    return false;
}



















