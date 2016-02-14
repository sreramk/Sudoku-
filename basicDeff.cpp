 /**
        basicDeff.cpp
        Su-do-ku solver V1.1
        copyright (c) 2015 K Sreram
        program author: K Sreram.         License: GNU General Public License, version 3 (GPL-3.0)
*/
#include "basicDeff.h"

void GridLimits::SetLimits(int pos_x, int pos_y)
{
    if(pos_x > 9 || pos_y > 9 || pos_x <= 0 || pos_y <=0)
    {
        return;
    }
    X_Top =  ( (int)((pos_x-1)/3) )*3;
    Y_Top =  ( (int)((pos_y-1)/3) )*3;
    X_End =  X_Top + 2; // +2 because, the starting position is denoted by X_top and crossing 2 units reaches the
                        // cell's end making it 3 steps in total (including the one at X_Top)
    Y_End =  Y_Top + 2;

    // GridNo = (Y_Top/3)*3 + X_top/3 + 1; Is same as,
     GridNo = Y_Top + X_Top/3 + 1;
}


bool Compare::operator () (PriorityUnit a, PriorityUnit b)
{
    return(a.PriorityValue < b.PriorityValue);
} 
