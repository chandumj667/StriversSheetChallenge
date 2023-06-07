/*
    Rotate Image by 90 degree
    Problem Statement: Given a matrix, your task is to rotate the matrix 90 degrees clockwise.

    Example 1:
    Input:  [
                [1,2,3],
                [4,5,6],
                [7,8,9]
            ]
    Output: [
                [7,4,1],
                [8,5,2],
                [9,6,3]
            ]
    Explanation: Rotate the matrix simply by 90 degree clockwise and return the matrix.

    Example 2:
    Input:  [
                [5,1,9,11],
                [2,4,8,10],
                [13,3,6,7],
                [15,14,12,16]
            ]
    Output: [
                [15,13,2,5],
                [14,3,4,1],
                [12,6,8,9],
                [16,7,10,11]
            ]
    Explanation: Rotate the matrix simply by 90 degree clockwise and return the matrix


    Brute force approach : 
        using an extra matrix to store the elements 
        the logic is ans[j][n-1-i] = mat[i][j]

        Time complexity : O(N^2)
        Space complexity : O(N^2)
    
    Optimal approach :
        first transpose the matrix 
            for this traverse the upper triangle of the matrix and swap the value with respective lower triangle cells
            and vice versa
        reverse each row of the matrix

        Time Complexity : O(N^2)
        Space complexity : O(1)
*/



#include<bits/stdc++.h>
using namespace std;


void print(vector<vector<int>>vec, int n , int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m;  j++){
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}


void brute(vector<vector<int>>vec, int n, int m){
    vector<vector<int>>ans(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++){
        for (int j = 0;  j<m; j++){
            ans[j][n-1 - i] = vec[i][j];
        }
    }
    cout << "Brute force approach :" << endl;
    print(ans, n, m);
    cout << endl;
}

void optimal(vector<vector<int>>vec, int n, int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){
            swap(vec[i][j], vec[j][i]);
        }
    }
    for (int i = 0; i<n; i++){
        reverse(vec[i].begin(), vec[i].end());
    }
    cout<< "Optimal approach " << endl;
    print(vec, n, m);

}


int main(){
    int n;
    int m;
    cout << "Enter the row and column sizes of the matrix ";
    cin >> n >> m;
    vector<vector<int>> mat;
    cout << "Enter the elements in to the matrix " << endl;
    for (int i = 0; i < n; i++){
        vector<int> row;
        for (int j = 0; j < m; j++){
            int ele;
            cin >> ele;
            row.push_back(ele);
        }
        mat.push_back(row);
    }
    cout << endl;

    print(mat, n, m);
    cout << endl;
    brute(mat, n, m);
    optimal(mat, n, m);
    return 0;
}