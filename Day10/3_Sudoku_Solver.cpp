/*

    Sudoku Solver
    Problem Statement:
    Given a 9×9 incomplete sudoku, solve it such that it becomes valid sudoku. Valid sudoku has the following properties.
            1. All the rows should be filled with numbers(1 – 9) exactly once.
            2. All the columns should be filled with numbers(1 – 9) exactly once.
            3. Each 3×3 submatrix should be filled with numbers(1 – 9) exactly once.
    Note: Character ‘.’ indicates empty cell.


    Input:
    Output:
    https://lh5.googleusercontent.com/k78fKDRjAJU3CIBgMRYCDEG93ndte0k85JLWYK6IumRreKBRv5zcKDkc1Ms_E6Bi_2M4twPY5GWos_0kQNkZO9AXRtowc5sKe5KZMJpcCqKddtXDr7xuA-HZDIttJ_-5RE30NlDJ


    Explanation:
    The empty cells are filled with the possible numbers. There can exist many such arrangements of numbers. The above solution is one of them. Let’s see how we can fill the cells below.

    Approach: 
        using recursion as we check for N-queens problem same like that we check if the element is '-' then loop it from 1 to 9 and check whether the row or col or the 3*3 grid contains of an element i from 1 to 9 if any one element have space then keep it in the empty space

        recursively do this until the correct elements pushed in to the container

        Time complexity:
*/


#include<bits/stdc++.h>
using namespace std;



bool isv(vector<vector<char>>&board, int r, int c, char a){
    for (int i = 0; i < 9; i++){
        if(board[i][c] == a){
            return false;
        }
        if(board[r][i] == a)
            return false;
        if(board[3*(r/3)+i/3][3*(c/3)+i%3] == a){
            return false;
        }
    }
    return true;
}

bool solve_sudoku(vector<vector<char>>&board){
    cout << "\nflag-2";

    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board[0].size(); i++){
            if(board[i][j] == '-'){
                for (int c = '1'; c <= '9'; c++){
                    if(isv(board, i, j, c)){
                        board[i][j] = c;

                        if(solve_sudoku(board))
                            return true;
                        else
                            board[i][j] = '-';
                    }
                }
                return false;
            }
        }
    }
    return true;
}



void print(vector<vector<char>>&vec){
    cout << "Valid sudoku is : " << endl;
    for(auto i:vec){
        cout << "| ";
        for(auto c:i){
            cout << c << " ";
        }
        cout << "|";
        cout << endl;
    }
}

int main(){
    int n = 9;
    vector<vector<char>> vec(n,vector<char>(n));
    cout << "Enter the elements or '-' in to the sudoku " << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> vec[i][j];
        }
    }
    solve_sudoku(vec);
    cout << "\nflag-10";

    print(vec);
    return 0;
}