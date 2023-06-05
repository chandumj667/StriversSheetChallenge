/*
    Program to generate Pascal’s Triangle
    Problem Statement: This problem has 3 variations. They are stated below:

    Variation 1: Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.

    Variation 2: Given the row number n. Print the n-th row of Pascal’s triangle.

    Variation 3: Given the number of rows n. Print the first n rows of Pascal’s triangle.

    In Pascal’s triangle, each number is the sum of the two numbers directly above it as shown in the figure below:

    Examples
    Example 1:
    Input Format: N = 5, r = 5, c = 3
    Result: 6 (for variation 1)
    1 4 6 4 1 (for variation 2)

    1
    1 1
    1 2 1
    1 3 3 1
    1 4 6 4 1    (for variation 3)

    Explanation: There are 5 rows in the output matrix. Each row is formed using the logic of Pascal’s triangle.

    Example 2:
    Input Format: N = 1, r = 1, c = 1
    Result: 1 (for variation 1)
        1 (for variation 2)
        1  (for variation 3)
    Explanation: The output matrix has only 1 row.

    For variation 1: we need to print the value present in row(r) and col(c)
        for that we need to calculate nCk formula ==> n == row-1 and k == c-1;

        nCk = n!/k!(n-k)!
        here n== row(r) k== col(c)
        therefore (r-1)! / (c-1)!*(r-c)!

        Time complexity : O(N*Col)

    For variation 2: We need to generate the entire row for the given n
            running a loop from 1 to n and use the ans variable to calculate each place
            ans = ans * (n-i)/i;

        Time complexity : O(N);
        Space complexity ; O(N)

    For variation 3:
        brute force:
            using nested loops and call the NCR function for each value and store the value in a vector<vector>

            Time complexity : O(N*N*r)
            Space complexity ; O(N*col)

        Optimal :
            using variation 2 to generate each row it reduce the time complexity;

            Time complexity : O(N^2)
            Space complexity : O(N^2)
*/



#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>>vec){
    for(auto r: vec){
        for(auto cele:r){
            cout << cele << " ";
        }
        cout << endl;
    }
}

// Brute force approach

int NCR(int n, int r){
    long long ans = 1;
    for (int i = 0; i<r; i++){
        ans *= (n - i);
        ans /= (i + 1);
    }
    return (int)ans;
}

vector<vector<int>>brute(int n){
    vector<vector<int>> vec;
    for (int i = 1; i <= n; i++){
        vector<int> col;
        for (int j = 1; j <= i; j++){
            col.push_back(NCR(i - 1, j - 1));
        }
        vec.push_back(col);
    }
    return vec;
}

// Optimal approach 

vector<int>roww(int r){
    long long ans = 1;
    vector<int>rr;
    rr.push_back(1);

    for (int i = 1; i<r; i++){
        ans *= (r - i);
        ans /= (i);
        rr.push_back(ans);
    }
    return rr;
}

vector<vector<int>>optimal(int n){
    vector<vector<int>> vec;
    for (int i = 1; i<=n; i++){
        vec.push_back(roww(i));
    }
    return vec;
}


int main(){
    int n;
    cout<<"Enter the number of rows to be generate ";
    cin >> n;
    cout << endl;
    // int r, c;
    // cout << "Enter row and col number to get a specific cell ";
    // cin >> r >> c;
    cout<<"Brute force approach "<<endl;
    vector<vector<int>>ans1 = brute(n);
    print(ans1);
    cout << endl;
    cout << "Optimal approach" << endl;
    vector<vector<int>> ans2 = optimal(n);
    print(ans2);
    return 0;
}