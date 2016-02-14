 /**
        File Name: InverseCount.h
        Su-do-ku solver V1.1
        copyright (c) 2015 K Sreram
        program author: K Sreram
        License: GNU General Public License, version 3 (GPL-3.0)
*/
#ifndef INVERSECOUNT_H
#define INVERSECOUNT_H
#include "basicDeff.h"
#include <vector>
const int Row  = 0;
const int Col  = 1;
const int Cell = 2;
class InvCount
{
public:

    float Count[3][9];
    void SetValues(InversePossibility& a);
    float Reterive(int Type, int pos);

};

extern const int Row;
extern const int Col;
extern const int Cell;
#endif // INVERSECOUNT_H
