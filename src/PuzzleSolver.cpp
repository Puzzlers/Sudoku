#include "PuzzleSolver.h"

#include <math.h>

std::map<std::string, PuzzleSolverGenerator> PuzzleSolver::m_registry;

PuzzleSolver* PuzzleSolver::getPuzzleSolver(const std::string& type)
{
    PuzzleSolver* solver = 0;

    std::map<std::string, PuzzleSolverGenerator>::iterator value = m_registry.find(type);

    if (value != m_registry.end()) {
        PuzzleSolverGenerator generator = value->second;
        if (generator)
            solver = (*generator)();
    }
    return solver;
}

bool PuzzleSolver::addToRegistry(const std::string& id, PuzzleSolverGenerator generator)
{
    m_registry[id] = generator;
    return true;
}
