 /**
        File Name: basicDeff.h
        Su-do-ku solver V1.1
        copyright (c) 2015 K Sreram
        program author: K Sreram
        License: GNU General Public License, version 3 (GPL-3.0)
*/

#ifndef BASICDFF_H
#define BASICDFF_H

#include <queue>
#include <deque>


class ErrorLogs{
public:
    unsigned int error;
};


enum POSSIB
        {
            POS1 = 0x1,
            POS2 = 0x1<<1,
            POS3 = 0x1<<2,
            POS4 = 0x1<<3,
            POS5 = 0x1<<4,
            POS6 = 0x1<<5,
            POS7 = 0x1<<6,
            POS8 = 0x1<<7,
            POS9 = 0x1<<8,
            POS_ALL = POS1 | POS2 | POS3 | POS4 |
                      POS5 | POS6 | POS7 | POS8 |
                      POS9
        };



int possibilityGen(int Value); // a value from 1 to 9

typedef int BoardGrid[9][9];
typedef int possibilitySet[9][9];
typedef float InversePossibility[9][9];

#ifdef DEBUG_TESTS
                    typedef float Waights[9][9];
#endif // DEBUG_TESTS

struct PriorityUnit{ /// this is a structure that shows the location of the cell
                       /// along with it's priority.
        float PriorityValue;
        int x; int y; // represents the location of the element
};

class Sudoku;
class Compare{
public:
     bool operator () (PriorityUnit a, PriorityUnit b);
};
struct GridLimits{
    int GridNo;
    int X_Top, Y_Top;
    int X_End, Y_End;
    void SetLimits(int pos_x, int pos_y);
};



typedef std::priority_queue<PriorityUnit, std::deque<PriorityUnit>, Compare> WaightQueue;

#endif // BASICDFF_H
