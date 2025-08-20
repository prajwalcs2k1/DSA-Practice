// Write a C++ program to print the minimum no. of moves required by a knight to reach the target-position from start position on a chessboard

#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<bool>> &vis, int x, int y){
    return (x>=0) && (x<8) && (y>=0) && (y<8) && !vis[x][y];
}

int findMinMoves(vector<vector<int>> &chessBoard, int x, int y){
    int xDir[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int yDir[] = {1, 2, 2, 1, -1, -2, -2, -1};
    vector<vector<bool>> vis(8, vector<bool>(8, false));
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(x, y), 0));
    vis[x][y] = true;
    while(!q.empty()){
        int currX = q.front().first.first;
        int currY = q.front().first.second;
        int move = q.front().second;
        q.pop();
        if(chessBoard[currX][currY] == 2) return move;
        for(int i=0; i<8; i++){
            int newX = currX + xDir[i];
            int newY = currY + yDir[i];
            if(isValid(vis, newX, newY)){
                vis[newX][newY] = true;
                q.push({{newX, newY}, move+1});
            }
        }
    }
    return -1;
}

int main(){

    vector<vector<int>> chessBoard(8, vector<int>(8, 0));
    int x1,y1,x2,y2;
    cout<<"Enter the start position indices [0 indexed] : ";
    cin>>x1>>y1;
    if((x1<0) || (x1>=8) || (y1<0) || (y1>=8)){
        cout<<"Invalid positions!!\n";
        return 0;
    }
    chessBoard[x1][y1] = 1;
    cout<<"Enter the target position indices [0 indexed] : ";
    cin>>x2>>y2;
    if((x2<0) || (x2>=8) || (y2<0) || (y2>=8) || ((x1==x2) && (y1==y2))){
        cout<<"Invalid positions!!\n";
        return 0;
    }
    chessBoard[x2][y2] = 2;
    cout<<"Minimum no. of moves from start pos to target pos is : "<<findMinMoves(chessBoard, x1, y1)<<endl;
    return 0;
}