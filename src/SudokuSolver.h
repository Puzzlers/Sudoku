#ifndef SUDOKUSOLVER_H
#define SUDOKUSOLVER_H

#include "PuzzleSolver.h"

class SudokuSolver : public PuzzleSolver {
    bool solveSection(Grid &grid, unsigned sectionNumber, unsigned initValue);
public:
    bool solve(Grid &grid);
};

#endif // SUDOKUSOLVER_H
