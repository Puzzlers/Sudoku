#include "Grid.h"

#include <iostream>

using namespace std;

Grid::Grid(unsigned rows, unsigned cols)
{
    m_rows = rows;
    m_cols = cols;
    m_grid = new int* [rows];
    for(unsigned i = 0; i < rows; i++)
        m_grid[i] = new int [cols];
}

Grid::~Grid()
{
    for(unsigned i = 0; i < m_rows; i++)
        delete [] m_grid[i];
    delete [] m_grid;
    m_grid = 0;
}

void Grid::fillCell(unsigned value, unsigned row, unsigned col)
{
    if(row < 0 || row >= m_rows || col < 0 || col >= m_cols) {
        cout << endl << "Error: Invalid Row or Col(" << row << "," << col << ")" << endl;
        return;
    }
    m_grid[row][col] = value;
}

unsigned Grid::getValueAt(unsigned row, unsigned col)
{
    if(row < 0 || row >= m_rows || col < 0 || col >= m_cols) {
        cout << endl << "Error: Invalid Row or Col(" << row << "," << col << ")" << endl;
        return -1;
    }
    return m_grid[row][col];
}

void Grid::display()
{
    for(unsigned i = 0; i < m_rows; i++) {
        for (unsigned j = 0; j< m_cols; j++)
            cout << m_grid[i][j] << " ";
        cout << endl;
    }
}
