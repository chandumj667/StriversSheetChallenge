/*
    N Queen Problem | Return all Distinct Solutions to the N-Queens Puzzle
    Problem Statement: The n-queens is the problem of placing n queens on n × n chessboard such that no two queens can attack each other. Given an integer n, return all distinct solutions to the n -queens puzzle. Each solution contains a distinct boards configuration of the queen’s placement, where ‘Q’ and ‘.’ indicate queen and empty space respectively.

    Input: n = 4
    Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]

*/


#include<bits/stdc++.h>
using namespace std;

/*
bool isok(int row, int col, vector<string>&board, int n){
    cout << "\n flag5";

    int rr = row;
    int cc = col;
    while(row>=0 && col>=0){
        if(board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }
    col = cc;
    row = rr;
    while(col>=0){
        if(board[row][col] == 'Q')
            return false;
        col--;
    }

    row = rr;
    col = cc;
    while(row>=0 && col>=0){
        if(board[row][col] == 'Q')
            return false;
        row++;
        col--;
    }
    return true;
}
*/

void queens(int col, vector<string>&board, vector<vector<string>>&ans, 
vector<int>&lrow, vector<int>&updig, vector<int>&lwdig, int n){
    if(col == n){
        ans.push_back(board);
        return;
    }

    for (int r = 0; r < n; r++){
        if(lrow[r] == 0 &&  lwdig[r+col] == 0 && updig[n-1+col-r] == 0){
            board[r][col] = 'Q';
            lrow[r] = 1;
            lwdig[r + col] = 1;
            updig[n - 1 + col - r] = 1;
            queens(col + 1, board, ans, lrow, updig, lwdig, n);
            board[r][col] = '_';
            lrow[r] = 0;
            lwdig[r + col] = 0;
            updig[n - 1 + col - r] = 0;

        }
    }
    
}

vector<vector<string>>solve(int n){
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '_');
    for (int i = 0; i < n; i++){
        board[i] = s;
    }

    // queens(0, board, ans, n);
    vector<int> lrow(n, 0);
    vector<int>updig(2*n-1, 0);
    vector<int> lwdig(2 * n - 1, 0);
    queens(0, board, ans, lrow, updig, lwdig, n);
    return ans;
}

void print(vector<vector<string>>&ans){
    for(auto r:ans){
        cout << "Board " << endl;
        for(auto i:r){
            cout << i << " ";
            cout << endl;
        }
        cout << endl;
    }

}

int main(){
    int n;
    cout << "Enter the N : ";
    cin >> n;
    vector<vector<string>> ans = solve(n);
    print(ans);
}