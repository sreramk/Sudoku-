 /**
        File Name: InverseCountSum.cpp
        Su-do-ku solver V1.1
        copyright (c) 2015 K Sreram
        program author: K Sreram
        License: GNU General Public License, version 3 (GPL-3.0)
*/
#include <iostream>
#include "inverseCountSum.h"


void InvCount::SetValues(InversePossibility& a)
{
    int i,j, k;//, c = 0;
    for(i= 0; i <9; ++i)
    {
        Count[Row][i] = 0.0;
        for(j=0; j<9; ++j)
            {
               // if(a[i][j] == 1)
                 //   c++;
                Count[Row][i] += a[i][j];
            }
        //Count[Row][i] = Count[Row][i]/c;

    }
    //c= 0;
    for(i= 0; i <9; ++i)
    {
        Count[Col][i] = 0.0;
        for(j=0; j<9; ++j)
            {
      //          if(a[j][i] == 1)
       //             ++c;
                Count[Col][i] += a[j][i];
            }
       // Count[Col][i] = Count[Col][i]/c;
    }
    //c = 0;
    for(k=0; k<9; ++k)
    {
        Count[Cell][k] = 0.0;
        for(i= (((int)(k/3)*3) ); i < (((int)(k/3)*3)) + 3; ++i)
            for(j= ((k*3) % 9); j < ((k*3) % 9) + 3; ++j)
            {
      //          if(a[j][i] == 1)
      //              ++c;
                Count[Cell][k] += a[i][j];
                //std::cout<<"  "<<Count[Cell][k]<<"asasasd";
            }
        //Count[Cell][k] = Count[Cell][k]/c;
    }
}

float InvCount::Reterive(int Type, int pos)
{
    //std::cout<<"  "<<Count[Row][pos]<<" ";
    switch (Type)
    {
    case Row:
        return Count[Row][pos];
        break;
    case Col:
        return Count[Col][pos];
        break;
    case Cell:
        return Count[Cell][pos];
        break;
    default:
        return 0; // do nothing
    }
} 
