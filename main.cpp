 /**
        File Name: main.cpp
        Su-do-ku solver V1.1
        copyright (c) 2015 K Sreram
        program author: K Sreram
       License: GNU General Public License, version 3 (GPL-3.0)
*/

#include <iostream>
#include <ctime>
#include "Sudoku.h"
#include "CoreSolution.h"
#include <stdlib.h>
int main()
{
    clock_t begin, end;
    int i, j;
    std::cout <<"\n              Su-do-ku solver V1.1                "
              <<"\n--------------------------------------------------"
              <<"\ncopyright (c) 2015  K Sreram"
              <<"\napplication developers: K Sreram.\n";
    BoardGrid Grid;

   std::cout <<"\n\n\n enter the puzzle";
   for(i=0; i < 9; ++i)
        for(j=0; j<9; ++j)
            std::cin>> Grid[i][j];
    Sudoku S(Grid);
    Solver solve;

    Solver::initializeGP();
    solve.SetCurPuzzle(S);
    std::cout << " \n the original puzzle:\n";
    for (i = 0; i<9; ++i)
    {
        for (j = 0; j<9; ++j)
        {
            if((*S.RetGrid())[i][j]  == 0)
                std::cout <<" ? ";
            else
                std::cout <<" "<< (*S.RetGrid())[i][j] << " ";

        }
        std::cout<<"\n";
        //std::cout << "\n";
    }
    std::cout << "\n\n";
    begin = clock();
    solve.RecrussiveSolve();
    end = clock();
    std::cout << "\nThe solution :\n";
    if(Solver::IsSolutionSet)
    {
        for(i=0; i<9; ++i)
        {
            for(j=0; j<9; ++j)
            {
                std::cout<< (*Solver::SudokuSolution.RetGrid())[i][j] <<"  ";
            }
            std::cout << "\n";
        }
    }
    else
    {
        std::cout << "no solution found";
    }

    std::cout << "\n\ntime elapsed = " << (double)(end - begin) / CLOCKS_PER_SEC;
    std::cout << "\n Number of iterations :" <<Solver::Count << "\n";
    return 0;
}
