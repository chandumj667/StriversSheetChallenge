/*
    Median of Row Wise Sorted Matrix
    In this article we will solve the most asked coding interview problem: Median of Row Wise Sorted Matrix
    Problem Statement: Given a row-wise sorted matrix of size r*c, where r is no. of rows and c is no. of columns, find the median in the given matrix.
    Assume – r*c is odd

    Example 1:
    Input:
    r = 3 , c = 3
    1 4 9
    2 5 6
    3 8 7
    Output: Median = 5
    Explanation: If we find the linear sorted array, the array becomes 1 2 3 4 5 6 7 8 9
    So, median = 5

    Example 2:
    Input:
    r = 3 , c = 3
    1 3 8
    2 3 4
    1 2 5
    Output: Median = 3
    Explanation: If we find the linear sorted array, the array becomes 1 1 2 2 3 3 4 5 7 8
    So, median = 3

    Approach:
*/

#include<bits/stdc++.h>
using namespace std;


int smaller(vector<int>&r, int mid){
    int l = 0;
    int h = r.size() - 1;
    while(l<=h){
        int m = (l + h) >> 1;
        if(r[m] <= mid)
            l = m + 1;
        else
            h = m - 1;
    }
    return l;
}

int solve(vector<vector<int>>&mat, int n, int m){
    int low = 0;
    int high = 1e9;
    while(low<=high){
        int mid = (low+high)>>1;
        int cnt = 0;
        for (int i = 0; i<n; i++){
            cnt += smaller(mat[i], mid);
        }
        if(cnt<=(n*m)/2)
            low = mid + 1;
        else{
            high = mid - 1;
        }
    }

    return low;
}


int main(){
    int n;
    int m;
    cout << "Enter the row and column sizes of the matrix : ";
    cin >> n >> m;
    vector<vector<int>> vec(n, vector<int>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> vec[i][j];
        }
    }
    cout << "The median of the matrix is : " << solve(vec, n, m);
    return 0;
}