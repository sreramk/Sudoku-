 /**
        File Name: CoreSolution.h
        Su-do-ku solver V1.1
        copyright (c) 2015 K Sreram
        program author: K Sreram
        License: GNU General Public License, version 3 (GPL-3.0)
*/
#ifndef CORE_SOLUTION_
#define CORE_SOLUTION_

#include "basicDeff.h"
#include "Sudoku.h"

#include <stack>
class Solver;
typedef std::stack <Solver> SudokuStack;
class Solver
{
    WaightQueue Q;

public:
    Sudoku CurPuzzle;
    static Sudoku SudokuSolution;
    static bool IsSolutionSet;
    static int Count;
    static int GlobalPossibilities[9][9];
    static void initializeGP();
    void SetCurPuzzle(Sudoku P);
    bool RecrussiveSolve (); // this starts the main solution iteration process
};


#endif // CORE_SOLUTION_
