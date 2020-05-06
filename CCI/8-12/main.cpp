#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int GRID_SIZE = 3;

bool CheckValid(int* columns, int row1, int column1)
{
    for(int row2 = 0; row2 < row1; row2++)
    {
        int column2  = columns[row2];
        if(column1 == column2)
        {
            return false;
        }

        int columnDistance = abs(column2 - column1);
        int rowDistance = row2 - row1;
        if(columnDistance == rowDistance)
        {
            return false;
        }
    }

    return true;
}

void PlaceQueens(int row, int* columns, vector<vector<int>>& v)
{
    if(row == GRID_SIZE)
    {
        vector<int> buffer;
        for(int i=0; i<GRID_SIZE; i++)
        {
            buffer.push_back(columns[i]);
        }
        v.push_back(buffer);
    }
    else
    {
        for(int col = 0; col < GRID_SIZE; col++)
        {
            if(CheckValid(columns, row, col))
            {
                columns[row] = col;
                PlaceQueens(row+1, columns, v);
            }
        }
    }
    
}

int main()
{
    int a[GRID_SIZE];
    vector<vector<int>> v;
    
    PlaceQueens(0, a, v);

    for(auto c : v)
    {
        for(auto cc : c)
        {
            cout << cc << ", ";
        }

        cout << endl;
    }

    return 0;
}
