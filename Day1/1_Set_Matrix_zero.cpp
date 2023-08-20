/*
    Set Matrix Zero
    
    Problem Statement: Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix.
    hello 
    Examples 1:

    Input: 
    matrix= [
                [1,1,1],
                [1,0,1],
                [1,1,1]
            ]
    Output: [
                [1,0,1],
                [0,0,0],
                [1,0,1]
            ]
    Explanation: Since matrix[2][2]=0.Therfore the 2nd column and 2nd row wil be set to 0.
    

    Example 2:
    Input: 
    matrix= [
                [0,1,2,0],
                [3,4,5,2],
                [1,3,1,5]
            ]
    Output: [
                [0,0,0,0],
                [0,4,5,0],
                [0,3,1,0]
            ]
    Explanation:Since matrix[0][0]=0 and matrix[0][3]=0. Therefore 1st row, 1st column and 4th column will be set to 0


    Brute approach :
        traverse the entire matrix and if we encounter any cell as zero(0) then make them as -1 for all the nonzero element in the respective row and column 
        then again traverse the matrix make all the -1 elements to zero(0).

        Time complexity : O (M*N)*(M+N)+ (M*N)
        Space complexity : O(1)

    Better approach :
        If any row or column contains minumum of one  zero(0) in it then mark the respective row and column by having an array for all the rows and an array for all columns

        by using the two extra arrays for rows with n size array and for columns with m size array

        Time complexity : O(2*M*N) == > O(M*N)
        Space complexity : O(M) + O(N)

    Optimal :
        as we did in better approach we just need to change the  rows array and cols array as first row and first column of the given matrix to reduce the space complexity
        We take a variable for either column or row as [0][0] is common for both the rows arr and cols arr 
        Mark the zero element rows and cols index 
        and do the changes for all the rows and cols except 0th row and 0th col

        As we earlier take an extra variable for col or row -> if we take for col then solve the 0th col first 
        if we take a variable for rows then solve the 0th row first

        Time complexity : O(M*N)
        Space complexity : O(1)
*/


/*
    Topics :
        2D arrays,
        vector of vector
*/


#include<bits/stdc++.h>
using namespace std;

// Printing the  matrix 

void print(vector<vector<int>>vec, int n, int m){
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}


// Brute force approach
void mr(vector<vector<int>>&mat, int n, int m, int i){
    for (int j = 0; j<m; j++){
        if(mat[i][j] != 0){
            mat[i][j] = -1;
        }
    }
}


void mc(vector<vector<int>>&mat, int n, int m, int j){
    for (int i = 0; i<n; i++){
        if(mat[i][j] != 0){
            mat[i][j] = -1;
        }
    }
}

vector<vector<int>>brute_force(vector<vector<int>>mat, int n, int m){
    // take the parameter with reference as vector<vector<int>>&mat that doesn't need an extra space
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(mat[i][j]==0){
                mr(mat, n, m, i);
                mc(mat, n, m, j);
            }
        }
    }
    for (int i = 0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] == -1){
                mat[i][j] = 0;
            }
        }
    }
    return mat;
}

// Better approach 

vector<vector<int>>better(vector<vector<int>>mat, int n, int m){
    // take the parameter with reference as vector<vector<int>>&mat that doesn't need an extra space
    
    int row[n] = {0};
    int col[m] = {0};
    for (int i = 0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(row[i] || col[j]){
                mat[i][j] = 0;
            }
        }
    }
    return mat;
}


// Optimal approach
vector<vector<int>>optimal(vector<vector<int>>mat, int n, int m){
    // take the parameter with reference as vector<vector<int>>&mat that doesn't need an extra space
    int zeroth_col = 1;
    for (int i = 0; i<n; i++){
        for (int j = 0; j < m; j++){
            if(mat[i][j] == 0){
                mat[i][0] = 0;
                if(j!= 0){
                    mat[0][j] = 0;
                }
                else{
                    zeroth_col = 0;
                }
            }
        }
    }

    // leaving the first row and first col as we marked them to change the elements

    for(int i=1; i<n; i++){
        for (int j = 1; j < m; j++){
            if(mat[i][j] != 0){
                if(mat[i][0]==0 || mat[0][j]==0){
                    mat[i][j] = 0;
                }
            }
        }
    }

    if(mat[0][0] == 0){
        for (int j = 0; j<m; j++){
            mat[0][j] = 0;
        }
    }
    if(zeroth_col == 0){
        for (int i = 0; i < n; i++){
            mat[i][0] = 0;
        }
    }
    return mat;
}


int main(){
    int n;
    int m;
    cout << "Enter the row and column size of the matrix ";
    cin >> n >> m;
    vector<vector<int>> mat;
    cout << "enter element in to the " << n << " * " << m << " matrix" << endl;
    for (int i = 0; i < n; i++){
        vector<int> row;
        for (int j = 0; j < m; j++){
            int ele;
            cin >> ele;
            row.push_back(ele);
        }
        mat.push_back(row);
    }
    if(mat.size() ==0)
        print(mat, n, m);

    vector<vector<int>> vec1 = brute_force(mat, n, m);
    vector<vector<int>> vec2 = better(mat, n, m);
    vector<vector<int>> vec3 = optimal(mat, n, m);
    cout << endl;
    cout << "Using Brute force approach " << endl;
    print(vec1, n, m);
    cout << "Using Better approach " << endl;
    print(vec2, n, m);
    cout << "Using Optimal approach " << endl;
    print(vec3, n, m);
    return 0;
}
