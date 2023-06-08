/*
    Grid Unique Paths | Count paths from left-top to the right bottom of a matrix

    Problem Statement: Given a matrix m X n, count paths from left-top to the right bottom of a matrix with the constraints that from each cell you can either only move to the rightward direction or the downward direction.

    Example 1:

    Input Format: m = 2, n= 2
    Output: 2
    Explanation: From the top left corner there are total 2 ways to reach the bottom right corner:
    Step 1: Right ->> Down
    Step 2: Down ->> Right


    Example 2:

    Input Format: m = 2, n= 3
    Ouput: 3
    Explanation:  From the top left corner there is a total of 3 ways to reach the bottom right corner.
    Step 1: Right ->> Right ->> Down
    Step 2: Right ->> Down ->> Right
    Step 3: Down ->> Right->> Right


    Brute force approach :
        Using recursion we can get all possible paths based on the condition that move only rightwards or  downwards

        Time complexity : Exponential O(2^n)
        Space complexity: O(2^n) as we using recursion it is also exponential

    Better approach :
        slightly changing the recursive approach with dynamic approach 
        for that we need to store the visited paths in a 2d hashmap of size n*m

        with that we can  reduce the time complexity ans space complexity:
        Time complexity : O(n*m)
        Space complexity: O(n*m) + O(n*m)->recursive tree
    
    Optimal approach :
        by having the observations we make the problem as combination problem 
        we just need to move only right and down side 
        so basically for right side (m-1) times and down side (n-1) times 
        summation (m-1)+(n-1) ==> n+m-2 total times we have paths to travel
        the combinations are 
            for right side : n+m-2 C m-1
            or 
            for down side : n+m-2 C n-1

        anyone of the above will work 
        then do the NcR == N! / (R! (N-R)!)

        Time complexity : O(m-1) or O(n-1)
        Space complexity: O(1)

*/

#include<bits/stdc++.h>
using namespace std;


// Brute force approach :
int count(int i, int j, int n, int m){
    if(i == (n-1) && j== (m-1)){
        return 1;
    }
    if(i>=n || j>=m)
        return 0;
    else {
        return count(i + 1, j, n, m) + count(i, j + 1, n, m);
    }
}

int brute(int n, int m){
    return count(0, 0, n, m);
}


// Better approach :
int cnt(int i, int j, int n, int m, vector<vector<int>>vis){
    if(i == (n-1) && j == (m-1))
        return 1;
    if(i>=n || j>=m){
        return 0;
    }
    if(vis[i][j] != -1){
        return vis[i][j];
    }
    else{
        return vis[i][j] = cnt(i + 1, j, n, m, vis) + cnt(i, j + 1, n, m, vis);
    }
}

int better(int n, int m, vector<vector<int>>&vec){
    return cnt(0, 0, n, m, vec);
}


int optimal(int n, int m){
    int N = n + m - 2;
    int r = n - 1;
    double res = 1;
    for (int i = 1; i <= r; i++){
        res =res * (N - r + i) / i;
    }
    return (int)res;
}


int main(){
    int n;
    int m;
    cout<<"Enter the row and column sizes of the matrix : ";
    cin >> n;
    cin >> m;
    
    cout << "Brute force approach : ";
    cout<<brute(n, m);
    cout << endl;

    cout << "Better approach : ";
    vector<vector<int>> vec(n, vector<int>(m, -1));
    cout<<better(n, m, vec);
    cout << endl;

    cout << "Optimal approach : ";
    cout<<optimal(n, m);
}