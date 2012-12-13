#ifndef PUZZLESOLVER_H
#define PUZZLESOLVER_H

#include <string>
#include <map>

class Grid;

class PuzzleSolver;

typedef PuzzleSolver* (*PuzzleSolverGenerator)();

class PuzzleSolver {
public:
    static PuzzleSolver* getPuzzleSolver(const std::string& type);

    static bool addToRegistry(const std::string& id, PuzzleSolverGenerator generator);

    virtual bool solve(Grid &grid) = 0;

private:
    static std::map<std::string, PuzzleSolverGenerator> m_registry;
};

template<typename T>
PuzzleSolver* puzzleSolver()
{
    return new T();
}

#define REGISTER_PUZZLE_SOLVER(className, type) \
    bool _id##className = PuzzleSolver::addToRegistry(type, puzzleSolver<className>)

#endif // PUZZLESOLVER_H

