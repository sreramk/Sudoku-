 /**
        File Name:Sudoku.cpp
        Su-do-ku solver V1.1
        copyright (c) 2015 K Sreram
        program author: K Sreram.
       License: GNU General Public License, version 3 (GPL-3.0)
*/
#include "Sudoku.h"
#include <iostream>
Sudoku::Sudoku()
{
    // this defines a free grid without any values
    int i, j;
    for(i=0; i < 9; ++i)
        for(j=0; j < 9; ++j)
            {
                Grid[i][j] = 0;
                possibilities[i][j] = POS_ALL;
//                possibilityCount[i][j] = 9;
            }
    ZeroPossibilities = false;
}


Sudoku::Sudoku(BoardGrid grid)
{
    int i, j;
    for(i=0; i < 9; ++i)
        for(j=0; j < 9; ++j)
            {
                Grid[i][j] = grid[i][j];
                if(grid[i][j] == 0)
                    possibilities[i][j] = POS_ALL;
                else
                    possibilities[i][j] = 0x1 << (grid[i][j]-1);
//                possibilityCount[i][j] = 9;
            }
}

void Sudoku::SwitchNumbers( int Value1, int Value2)
{
    int i, j;
    for(i=0; i < 9; ++i)
        for(j=0; j < 9; ++j)
            {
                if(Grid[i][j] == Value1)
                    Grid[i][j] = Value2;
                else if(Grid[i][j] == Value2)
                    Grid[i][j] = Value1;
                //else do nothing
            }
}


bool Sudoku::DeleteValue(int Value, int& field)
{
    bool mod = ( (field & ((0x1 << (Value-1) ))) != 0);
    if(Value != 0)
        {
            field = field & (~(0x1 << (Value-1) ));
        }
    return mod;
}

void Sudoku::DeleteCommonElements(int Value_set, int& field)
{
    if(Value_set != 0)
        {
            field = field & (~Value_set );
        }
}

int Sudoku::BitValue(int Value) // returns the value that is present in the set Value
{
    int val;
    if(Value == 0) return 0;
    for(val = 0; val < 9; ++val)
    {
        if (((0x1<<val) & Value) != 0)
            return val+1;
    }
    return 0;
}

bool Sudoku::SinglePossibilityElement(int possib)
{
    return
    (
            possib == POS1 ||
            possib == POS2 ||
            possib == POS3 ||
            possib == POS4 ||
            possib == POS5 ||
            possib == POS6 ||
            possib == POS7 ||
            possib == POS8 ||
            possib == POS9
    );
}

bool Sudoku::ScreenPossibility(int pos_x, int pos_y)
{
    bool Modification = false;
    GridLimits Lim;
    int i,j;
    Lim.SetLimits(pos_x, pos_y);
    int possib = possibilities[pos_y-1][pos_x-1];
    //int possib = POS_ALL;
    // for variation in +ve x
    for(i= pos_y - 1, j = pos_x - 1; j < 9; ++j  )
        if(DeleteValue(Grid[i][j], possib))  Modification = true;

    // for variation in -ve x
    for(i= pos_y - 1, j = pos_x - 1; j >= 0; --j )
        if(DeleteValue(Grid[i][j], possib))  Modification = true;

    // for variation in +ve y
    for(i= pos_y - 1, j = pos_x - 1; i < 9; ++i  )
        if(DeleteValue(Grid[i][j], possib))  Modification = true;

    // for variation in -ve y
    for(i= pos_y - 1, j = pos_x - 1; i >= 0; --i )
        if(DeleteValue(Grid[i][j], possib))  Modification = true;

    for(i = Lim.Y_Top; i  <= Lim.Y_End; ++i  )
        for(j = Lim.X_Top; j  <= Lim.X_End; ++j  )
                DeleteValue(Grid[i][j], possib);

    possibilities[pos_y-1][pos_x-1] = possib;

    if (possib == 0x0) // sets the trigger for zero possibilities
        ZeroPossibilities = true;
    //(possibilityCount[pos_y - 1][pos_x -1] -= count);
    //std::cout<<possibilityCount[pos_y - 1][pos_x -1];
    if(SinglePossibilityElement(possib))
        {
            Grid[pos_y-1][pos_x-1] = BitValue(possibilities[pos_y - 1][pos_x -1]);
            //std::cout<<"\n\n Got You!" <<  possibilities[pos_y - 1][pos_x -1]<<"\n";
        }
    return Modification;
}

bool Sudoku::FullPossibility() // returns false if the possibility has zero in it
{
        return ZeroPossibilities; // only works if the Solve() is called
}
bool Sudoku::Solve()
{
    ZeroPossibilities = false;
    bool ret = false;
    //bool ret2 = false;
    for(int i=0; i<9; ++i)
        for(int j=0; j<9; ++j)
    {
        if (Grid[i][j] == 0)
        {
            if (ScreenPossibility(j + 1, i + 1))
                ret = true;
        }
        else
            possibilities[i][j] = 1;

    }
    return ret;
}

BoardGrid* Sudoku::RetGrid()
{
    return &Grid;
}

BoardGrid* Sudoku::RetPoss()
{
    return &possibilities;
}

void Sudoku::SetGrid(BoardGrid grid)
{
    (*this) = Sudoku(grid);
}


bool Sudoku::CheckLegal(BoardGrid b) // this is used for checking only complete solutions
{
    int x, y;
    Sudoku Temp (b);
    for(y = 1; y <= 9; ++y)
        for(x= 1; x <= 9; ++x)
            {
                Temp.ScreenPossibility(x, y); // screens all the possibilities
                if(!Temp.FullPossibility())
                    return false;
                /*if(!SinglePossibilityElement((*Temp.RetPoss())[y-1][x-1]))
                    return false;
                    */
            }
    return true;
}


bool Sudoku::IsLegal()
{
    return CheckLegal(Grid);
}


void Sudoku::SetPossibilityCount()
{
    PossibCount.SetValues(possibilityCountI);
}

bool Sudoku::IsSolved()
{
    for(int i=0; i<9; ++i)
        for(int j=0; j<9; ++j)
            if(Grid[i][j] == 0)
                return false;
    return true;

}

void Sudoku::reinitializepos()
{
    int i, j;
    for (i = 0; i < 9; ++i)
        for (j = 0; j < 9; ++j)
        {
            possibilities[i][j] = POS_ALL;
            //                possibilityCount[i][j] = 9;
        }

}
