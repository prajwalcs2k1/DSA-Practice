// Write a C++ program to print the BFS traversal in a 2D grid given the position (i,j)

#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<bool>> &vis, int rows, int cols, int x, int y){
    return (x >= 0) && (x < rows) && (y >= 0) && (y < cols) && !vis[x][y];
}

void BFS(vector<vector<int>> &grid, int rows, int cols, int i, int j){
    vector<vector<bool>> vis(rows, vector<bool>(cols, false));
    int iDir[] = {-1, 0, 1, 0};
    int jDir[] = {0, 1, 0, -1};
    queue<pair<int, int>> q;
    vis[i][j] = true;
    q.push(make_pair(i, j));

    while(!q.empty()){
        int currI = q.front().first;
        int currJ = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            if(isValid(vis, rows, cols, currI + iDir[i], currJ + jDir[i])){
                q.push({currI + iDir[i], currJ + jDir[i]});
                vis[currI + iDir[i]][currJ + jDir[i]] = true;
                grid[currI + iDir[i]][currJ + jDir[i]] = grid[currI][currJ] + 1;
            }
        }
    }

    return;
}

int main(){

    int rows, cols;
    cout<<"Enter the rows & cols of the grid : ";
    cin>>rows>>cols;
    vector<vector<int>> grid(rows, vector<int>(cols, 0));
    int i, j;
    cout<<"Enter the starting position (0 indexed): ";
    cin>>i>>j;
    if((i<0) || (i>=rows) || (j<0) || (j>=cols)){
        cout<<"Invalid starting position!!\n";
        return 0;
    }
    BFS(grid, rows, cols, i, j);
    cout<<"Grid after BFS traversal : \n";
    for(int i=0; i<rows; i++){
        for(int cell : grid[i]) cout<<cell<<" ";
        cout<<"\n";
    }
    return 0;
}