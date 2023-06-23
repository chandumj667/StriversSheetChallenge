/*
    Rat in a Maze

    Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N – 1, N – 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are ‘U'(up), ‘D'(down), ‘L’ (left), ‘R’ (right). Value 0 at a cell in the matrix represents that it is blocked and the rat cannot move to it while value 1 at a cell in the matrix represents that rat can travel through it.

    Note: In a path, no cell can be visited more than one time.
    Print the answer in lexicographical(sorted) order


    Example 1:
    Input:
    N = 4
    m[][] = {{1, 0, 0, 0},
            {1, 1, 0, 1},
            {1, 1, 0, 0},
            {0, 1, 1, 1}}
    Output: DDRDRR DRDDRR
    Explanation:
    The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.

    Example 2:
    Input: N = 2
        m[][] = {{1, 0},
                    {1, 0}}
    Output:
    No path exists and the destination cell is blocked.

    Approach: 
        by using recursion and maintaining a visited matrix to avoid infinite recursion 
        moving in a lexicographical order D/L/R/U
        and if there is any path we move forward ans make the cell as visited if not we come back and make that cell as unvisited

        Time complexity: O(4^(m*n))
        Space complexity: O(m*n)
*/

#include<bits/stdc++.h>
using namespace std;


void solve(int i, int j, vector<vector<int>>&m, int n, vector<string>&ans, string move, vector<vector<int>>&vis ){
    if(i==n-1 && j==n-1){
        ans.push_back(move);
        return;
    }

    //Down
    if(i+1<n && !vis[i+1][j] && m[i+1][j] == 1){
        vis[i][j] = 1;
        solve(i + 1, j, m, n, ans, move + 'D', vis);
        vis[i][j] = 0;
    }

    //Left
    if(j-1>=0 && !vis[i][j-1] && m[i][j-1] == 1){
        vis[i][j] = 1;
        solve(i, j - 1, m, n, ans, move + 'L', vis);
        vis[i][j] = 0;
    }

    // Right
    if(j+1<n && !vis[i][j+1] && m[i][j+1] == 1){
        vis[i][j] = 1;
        solve(i, j + 1, m, n, ans, move + 'R', vis);
        vis[i][j] = 0;
    }

    // Up
    if(i-1>=0 && !vis[i-1][j] && m[i-1][j]==1){
        vis[i][j] = 1;
        solve(i - 1, j, m, n, ans, move + 'U', vis);
        vis[i][j] = 0;
    }
}

vector<string>path(vector<vector<int>>&vec, int n){
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));

    if(vec[0][0] == 1)
        solve(0, 0, vec, n, ans, "", vis);
    return ans;
}

void print(vector<string>&out){
    for(auto i:out){
        cout << "Path is : " ;
        cout << i << endl;
    }
}

int main(){
    int n;
    cout<<"Enter the size of the square matrix : ";
    cin >> n;
    vector<vector<int>>vec(n, vector<int>(n));
    cout << "Enter the elements in to " << n << "*" << n << " Matrix :" << endl;
    ;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> vec[i][j];
        }
    }
    vector<string> out = path(vec, n);
    print(out);
    return 0;
}


