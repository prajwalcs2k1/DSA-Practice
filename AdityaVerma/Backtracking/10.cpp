// Write a C++ program to solve a Sudoku Solver

/*
    T.C. of the below code is O(9^(n*n)) = O(9^81)
    Each cell takes atmost 9 possible checks
*/

#include<bits/stdc++.h>
using namespace std;

bool checkRow(vector<vector<int>> &sudoku, int number, int row){

    for(int i=0; i<9; i++){
        if(sudoku[row][i] == number) return false;
    }

    return true;
}

bool checkCol(vector<vector<int>> &sudoku, int number, int col){

    for(int i=0; i<9; i++){
        if(sudoku[i][col] == number) return false;
    }

    return true;
}

bool checkGrid(vector<vector<int>> &sudoku, int number, int row, int col){

    row = (row / 3) * 3;
    col = (col / 3) * 3;

    for(int i=row; i<(row + 3); i++){
        for(int j=col; j<(col+3); j++){
            if(sudoku[i][j] == number) return false;
        }
    }

    return true;
}

bool isValid(int number, vector<vector<int>> &sudoku, int row, int col){
    return checkRow(sudoku, number, row) && checkCol(sudoku, number, col) && checkGrid(sudoku, number, row, col);
}

bool sudokuSolverHelper(vector<vector<int>> &sudoku, int row, int col, int n, int m){
    if(row >= n) return true;

    int nextRow = (col == (m-1)) ? row + 1 : row;
    int nextCol = (col == (m-1)) ? 0 : col + 1;
    if(sudoku[row][col] != 0) return sudokuSolverHelper(sudoku, nextRow, nextCol, n, m);

    for(int i=1; i<=9; i++){
        if(isValid(i, sudoku, row, col)){
            sudoku[row][col] = i;
            if(sudokuSolverHelper(sudoku, nextRow, nextCol, n, m)) return true;
            sudoku[row][col] = 0;
        }
    }

    return false;
}

void solveSudoku(vector<vector<int>> &sudoku){

    sudokuSolverHelper(sudoku, 0, 0, sudoku.size(), sudoku[0].size());

    return;
}

void displaySudoku(vector<vector<int>> &sudoku){
    cout<<"[\n";
    for(int i=0; i<sudoku.size(); i++){
        cout<<" [ ";
        for(int j=0; j<sudoku[i].size(); j++){
            cout<<sudoku[i][j];
            if(j != (sudoku[i].size()-1)) cout<<", ";
        }
        cout<<" ]\n";
    }
    cout<<"]\n";
    return;
}

int main(){

    vector<vector<int>> sudoku = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    solveSudoku(sudoku);

    displaySudoku(sudoku);

    return 0;
}