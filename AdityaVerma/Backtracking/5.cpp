// Writen a CPP program to solve Rat In a Maze problem

#include<bits/stdc++.h>
using namespace std;

bool isCellValid(vector<vector<int>> &maze, int row, int col, int n, int m){
    if((row < 0) || (col < 0) || (row >= n) || (col >= m) || (maze[row][col] == 0)) return false;
    return true;
}

void ratInAMaze(vector<vector<int>> &maze, int row, int col, int n, int m, vector<string> &paths, string path){
    if(!(isCellValid(maze, row, col, n, m))) return;
    if((row == n-1) && (col == m-1)){
        paths.push_back(path);
        return;
    }
    maze[row][col] = 0;             // mark the cell as visited
    ratInAMaze(maze, row, col+1, n, m, paths, path + 'R');
    ratInAMaze(maze, row+1, col, n, m, paths, path + 'D');
    ratInAMaze(maze, row-1, col, n, m, paths, path + 'U');
    ratInAMaze(maze, row, col-1, n, m, paths, path + 'L');
    maze[row][col] = 1;             // undo the visited markings
    return;
}

void printPaths(vector<string> paths){
    if(paths.size() == 0){
        cout<<"No valid paths exists!!\n";
        return;
    }
    cout<<"Paths are as follows : \n";
    for(string str : paths) cout<<str<<endl;
    return;
}

int main(){
    vector<vector<int>> maze = {
        {1,1,1,1},
        {1,0,1,1},
        {1,1,0,1},
        {0,1,1,1}
    };

    vector<string> paths;
    ratInAMaze(maze, 0, 0, maze.size(), maze[0].size(), paths, "");

    printPaths(paths);

    return 0;
}