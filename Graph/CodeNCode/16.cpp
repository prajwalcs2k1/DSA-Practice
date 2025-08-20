// Write a C++ program to find the no. of connected components of a 2D grid

#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<int>> &grid, vector<vector<bool>> &vis, int i, int j, int rows, int cols){
    return (i < rows) && (i >= 0) && (j < cols) && (j >= 0) && !vis[i][j] && (grid[i][j] != 0) ; 
}

void dfs(vector<vector<int>> &grid, vector<vector<bool>> &vis, int i, int j, int rows, int cols){
    vis[i][j] = true;
    if(isValid(grid, vis, i-1, j, rows, cols)) dfs(grid, vis, i-1, j, rows, cols);      // up
    if(isValid(grid, vis, i, j+1, rows, cols)) dfs(grid, vis, i, j+1, rows, cols);      // right
    if(isValid(grid, vis, i+1, j, rows, cols)) dfs(grid, vis, i+1, j, rows, cols);      // down
    if(isValid(grid, vis, i, j-1, rows, cols)) dfs(grid, vis, i, j-1, rows, cols);      // left
    return;
}

void findConnectedComponents(vector<vector<int>> &grid){
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<bool>> vis(rows, vector<bool>(cols, false));
    int count = 0;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if((grid[i][j] == 1) && !vis[i][j]){
                dfs(grid, vis, i, j, rows, cols);
                count++;
            }
        }
    }
    cout<<"Total no. of connected components in the given graph is : "<<count<<endl;

    return;
}

int main(){

    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 1, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 0, 0, 0}
    };
    findConnectedComponents(grid);
    return 0;
}