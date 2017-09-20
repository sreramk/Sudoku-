/**
        File Name: Sudoku.h
        Su-do-ku solver V1.1
        copyright (c) 2015 K Sreram
        program author: K Sreram
        License: GNU General Public License, version 3 (GPL-3.0)
*/
#ifndef SUDOKU_H
#define SUDOKU_H
#include "InverseCountSum.h"
#include "basicDeff.h"
class Sudoku
{
    // shows if there is a possibility for zero to be present in the possibilities variable
    bool ZeroPossibilities;

    BoardGrid Grid; // shows one sudoku board; (x, y) represents the position and the value
                    // field represents the value
        BoardGrid possibilities;
        BoardGrid possibilityCount;
        InversePossibility possibilityCountI; // inverse count (this serves as the exact inverse of the
                                          // possibilityCount.
        InvCount PossibCount;

                    /// only for debug purpose
                #ifdef DEBUG_TESTS
                        Weights weight_values; // holds the weights
                #endif // DEBUG_TESTS
    //BoardGrid possibilityCount;
    public:

                     PriorityUnit TempPUnit;

        Sudoku();
        Sudoku (BoardGrid grid);
        void SetGrid(BoardGrid grid);
        // this is the basic operation involved in converting the sudoku puzzle into a different sequence.
        void SwitchNumbers(int Value1, int Value2); // interchanges the values without making
                                                                // any mistakes by violating the fundamental rules
        bool ScreenPossibility(int pos_x, int pos_y); // screens the possibility of numbers that can fit.
        bool ScreenPossibilityL2(int pos_x, int pos_y);
        static bool CheckLegal(BoardGrid); // same as IsLegal(), but takes the board as the input
        bool IsLegal(); // checks if the current board is legal (or correctly follows the rules)
        static bool DeleteValue(int Value, int &field); // deletes the bit field (making it zero) which is at the position "value".
                                                        // "field" is a bit-vice set, holding the possibilities the cell can hold.
        void DeleteCommonElements(int Value_set, int& field );
        static int BitValue(int Value);
        BoardGrid* RetGrid();
        BoardGrid* RetPoss();
        static bool SinglePossibilityElement(int possib);
        static int NoOfElements(int value);
        bool Solve();

        void GeneratePossibilityCount();
        void GenerateInversePossibilityCount();
        void SetPossibilityCount();
        void GenerateWeightValues(InvCount& inv, WeightQueue& Q,  int pos_x, int pos_y);
        WeightQueue GenerateWeightValues();
        void reinitializepos();

        bool IsSolved();
        bool FullPossibility();

};



#endif // SUDOKU_H
