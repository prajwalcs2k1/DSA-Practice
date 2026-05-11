// Write a C++ program to solve N-Queens problem

#include<bits/stdc++.h>
using namespace std;

bool checkVertical(vector<vector<int>> &board, int col, int N){
    int i=0;
    while(i<N){
        if(board[i][col] == 1) return false;
        i++;
    }

    return true;
}

bool checkLeftUpperDiag(vector<vector<int>> &board, int row, int col){
    while((row >=0) && (col >= 0)){
        if(board[row][col] == 1) return false;
        row--;
        col--;
    }

    return true;
}

bool checkRightUpperDiag(vector<vector<int>> &board, int row, int col, int N){
    while((row >=0) && (col < N)){
        if(board[row][col] == 1) return false;
        row--;
        col++;
    }

    return true;
}

bool isValid(vector<vector<int>> &board, int row, int col, int N){
    return checkVertical(board, col, N) && checkLeftUpperDiag(board, row, col) && checkRightUpperDiag(board, row, col, N);
}

void NQueensHelper(vector<vector<string>> &res, int N, int row, vector<string> aux, vector<vector<int>> &board){
    if(row >= N){
        res.push_back(aux);
        return;
    }

    string currPath(N, '.');
    for(int i=0; i<N; i++){
        if(isValid(board, row, i, N)){
            currPath[i] = 'Q';
            aux.push_back(currPath);
            board[row][i] = 1;
            NQueensHelper(res, N, row+1, aux, board);
            aux.pop_back();
            currPath[i] = '.';
            board[row][i] = 0;
        }
    }

    return;
}

void NQueens(int N, vector<vector<string>> &res){
    vector<vector<int>> board(N, vector<int>(N, 0));
    vector<string> aux;
    NQueensHelper(res, N, 0, aux, board);

    return;
}

void displayPaths(vector<vector<string>> res){
    cout<<"[\n";
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++){
            cout<<"     "<<res[i][j]<<endl;
        }

        if(i != (res.size()-1)) cout<<",";
        cout<<"\n";
    }
    cout<<"]\n";

    return;
}

int main(){

    int N;
    cout<<"Enter the value of N : ";
    cin>>N;
    vector<vector<string>> res;
    NQueens(N, res);
    displayPaths(res);
    return 0;
}