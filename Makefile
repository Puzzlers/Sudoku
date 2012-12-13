CXX ?= g++
CXX_FLAGS =-c -Wall

all: sudoku

sudoku: main.o Grid.o PuzzleSolver.o SudokuGrid.o SudokuSolver.o
	$(CXX) main.o Grid.o PuzzleSolver.o SudokuGrid.o SudokuSolver.o -o sudoku

main.o: src/main.cpp
	$(CXX) $(CXX_FLAGS) src/main.cpp

Grid.o: src/Grid.cpp
	$(CXX) $(CXX_FLAGS) src/Grid.cpp

PuzzleSolver.o: src/PuzzleSolver.cpp
	$(CXX) $(CXX_FLAGS) src/PuzzleSolver.cpp

SudokuGrid.o: src/SudokuGrid.cpp
	$(CXX) $(CXX_FLAGS) src/SudokuGrid.cpp

SudokuSolver.o: src/SudokuSolver.cpp
	$(CXX) $(CXX_FLAGS) src/SudokuSolver.cpp

clean: 
	rm -rf *.o sudoku

