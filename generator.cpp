 /**
        File Name: generator.cpp
        Su-do-ku solver V1.1
        copyright (c) 2015 K Sreram
        program author: K Sreram
        License: GNU General Public License, version 3 (GPL-3.0)
*/
#include <iostream>
#include "Sudoku.h"
#include "InverseCountSum.h"
int Sudoku::NoOfElements(int value)
{

    int tcount = 0;
    if( (value & POS1) != 0) ++tcount;
    if( (value & POS2) != 0) ++tcount;
    if( (value & POS3) != 0) ++tcount;
    if( (value & POS4) != 0) ++tcount;
    if( (value & POS5) != 0) ++tcount;
    if( (value & POS6) != 0) ++tcount;
    if( (value & POS7) != 0) ++tcount;
    if( (value & POS8) != 0) ++tcount;
    if( (value & POS9) != 0) ++tcount;
    return tcount;
}



void Sudoku::GeneratePossibilityCount() // this is to be called only after calling the
{                                       // screen possibility function for all (x,y) coordinates
    int i,j;
    for(i=0; i<9; ++i)
        for(j=0; j<9; ++j)
            possibilityCount[i][j] = NoOfElements(possibilities[i][j]);
}

void Sudoku::GenerateInversePossibilityCount() // this is to be called after the GeneratePossibilityCount() is called
{
    int i,j;
    for(i=0; i<9; ++i)
        for(j=0; j<9; ++j)
            {
                possibilityCountI[i][j] = (float)(1/(float)possibilityCount[i][j]);
                //std::cout<<":: "<<possibilityCountI[i][j]<<" ";
            }
}


void Sudoku::GenerateWeightValues(InvCount& inv, WeightQueue& Q, int pos_x, int pos_y)
{
    GridLimits Lim;
    Lim.SetLimits(pos_x, pos_y);
    TempPUnit.PriorityValue = inv.Reterive(Row, pos_x - 1) +
        inv.Reterive(Col, pos_y - 1) +
        inv.Reterive(Cell, Lim.GridNo - 1)+
                                      10*possibilityCountI[pos_y-1][pos_x-1];
    TempPUnit.x = pos_x -1;
    TempPUnit.y = pos_y -1;
    Q.push(TempPUnit);
}

WeightQueue Sudoku::GenerateWeightValues()
{
    WeightQueue Q;
    int i,j;
    for(i=1; i<=9; ++i)
        for(j=1; j<=9; ++j)
        {
            if (Grid[i-1][j-1] == 0)
                GenerateWeightValues(PossibCount, Q, j, i);
        }
        return Q;
} 
