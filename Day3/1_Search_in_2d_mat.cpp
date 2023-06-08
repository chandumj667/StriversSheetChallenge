/*
    Search in a sorted 2D matrix
    Problem Statement: Given an m*n 2D matrix and an integer, write a program to find if the given integer exists in the matrix.

    Given matrix has the following properties:

    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row
    
    
    Example 1:

    Input: matrix =
    [[1,3,5,7],
    [10,11,16,20],
    [23,30,34,60]],
    target = 3
    Output: true
    Explanation: As the given integer(target) exists in the given 2D matrix, the function has returned true.
    
    
    Example 2:

    Input: matrix =
    [[1,3,5,7],
    [10,11,16,20],
    [23,30,34,60]],
    target = 13
    Output: false
    Explanation: As the given integer(target) does not exist in the given 2D matrix, the function has returned false.

    Brute force :
        traverse in the given matrix with nested loops and find the element if found return true else false 
        Time complexity : O(N*M)
        Space complexity : O(1)
    

    optimal approach :
        hint is the matrix is sorted then we can do binary search in it 
        Time complexity : O(log(N*M))
        Space complexity : O(1)
*/


#include<bits/stdc++.h>
using namespace std;


bool brute(vector<vector<int>>mat, int n, int m, int t){
    cout << "Brute force approach : ";
    for(auto r:mat){
        for(auto e:r){
            if(e == t)
                return true;
        }
    }
    return false;
}

bool optimal(vector<vector<int>>mat, int n, int m, int t){
    cout << "Optimal approach : ";
    int i = 0;
    int j = m - 1;
    while(i<n && j>=0){
        if(mat[i][j] == t){
            return true;
        }
        if(mat[i][j] > t){
            j--;
        }
        else {
            i++;
        }
    }
    return false;
}

int main(){
    int n;
    int m;
    cout << "Enter the row and col size of the matrix ";
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    cout << "Enter elements in to the matrix with " << n << " rows and " << m << " columns" << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }
    int target;
    cout << "Enter the element to be searched ";
    cin >> target;
    bool flag1 = brute(mat, n, m, target);
    if(flag1){
        cout << "Element found in the matrix" << endl;
    }
    else{
        cout << "Element not found in the matrix" << endl;
    }

    bool flag2 = optimal(mat, n, m, target);
    if (flag2)
    {
        cout << "Element found in the matrix" << endl;
    }
    else
    {
        cout << "Element not found in the matrix" << endl;
    }
}