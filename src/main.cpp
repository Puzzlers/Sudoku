#include "PuzzleSolver.h"
#include "SudokuGrid.h"

int main()
{
    SudokuGrid sudoku;
    PuzzleSolver* solver = PuzzleSolver::getPuzzleSolver("Sudoku");

    if (solver)
        solver->solve(sudoku);

    return 0;
}
