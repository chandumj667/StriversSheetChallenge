/*
    Find minimum number of coins
    Problem Statement: Given a value V, if we want to make a change for V Rs, and we have an infinite supply of each of the denominations in Indian currency, i.e., we have an infinite supply of { 1, 2, 5, 10, 20, 50, 100, 500, 1000} valued coins/notes, what is the minimum number of coins and/or notes needed to make the change.


    Example 1:
    Input: V = 70
    Output: 2
    Explanation: We need a 50 Rs note and a 20 Rs note.

    Example 2:
    Input: V = 121
    Output: 3
    Explanation: We need a 100 Rs note, a 20 Rs note and a 1 Rs coin.


    Approach:
        we traverse the denomination array from the last to the zeroth index 
        we cannot use the denomination which is grater than the given value V
        get the greatest among the values which are less than the value V

        Time complexity : O(V)
        Space complexity: O(n) to give the combinations of the coins and number of times that denomination taken

*/

#include<bits/stdc++.h>
using namespace std;

void print(vector<pair<int, int>>vpp){
    for(auto i: vpp){
        cout << "Coin/Note : '" << i.first << "' and no. of times : '" << i.second << "' " << endl;
    }
}

vector<pair<int, int>>solve(int v){
    int arr[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = 9;
    vector<pair<int, int>> vp;
    for (int i = n - 1; i >= 0; i--){
        int count = 0;
        while(v>=arr[i]){
            pair<int, int> p;
            count++;
            v -= arr[i];
            p.first = arr[i];
            p.second = count;
            vp.push_back(p);
        }
    }
    return vp;
}

int main(){
    int v;
    cout << "Enter the value : ";
    cin >> v;
    vector<pair<int, int>> vpp = solve(v);
    print(vpp);
    return 0;
}