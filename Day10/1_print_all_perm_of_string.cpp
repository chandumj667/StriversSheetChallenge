/*
    Print All Permutations of a String/Array
    Problem Statement: Given an array arr of distinct integers, print all permutations of String/Array.

    Example 1:
    Input: arr = [1, 2, 3]
    Output:
    [
    [1, 2, 3],
    [1, 3, 2],
    [2, 1, 3],
    [2, 3, 1],
    [3, 1, 2],
    [3, 2, 1]
    ]
    Explanation: Given an array, return all the possible permutations.

    Example 2:
    Input: arr = [0, 1]
    Output:
    [
    [0, 1],
    [1, 0]
    ]
    Explanation: Given an array, return all the possible permutations.


    Approach 1:
        Using recursion we can get all the permutations of the given arr
        by maintaining a map and a list to return all the possible permutations

        Time complexity : O(n! * n)
        Space complexity : O(n)
*/


#include<bits/stdc++.h>
using namespace std;


void brute(vector<int>&ds,vector<int>&inp, vector<vector<int>>&ans, unordered_map<int, int>&ump){
    if(ds.size() == inp.size()){
        ans.push_back(ds);
        return;
    }

    for (int i = 0; i < inp.size(); i++){
        if(!ump[i]){

            ds.push_back(inp[i]);
            ump[i] = 1;

            brute(ds, inp, ans, ump);
            ump[i] = 0;
            ds.pop_back();
        }
    }
}


vector<vector<int>>solve(vector<int>inp, int n){
    vector<int> ds;
    unordered_map<int, int> ump;
    // int ump[inp.size()];
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++){
        ump[i] = 0;
    }
    brute(ds, inp, ans, ump);
    return ans;
}


void print(vector<vector<int>>&ans){
    cout << "[" << endl;
    for(auto r:ans){
        cout << "    [";
        for(auto c:r){
            cout << c << " ";
        }
        cout << "]";
        cout << endl;
    }
    cout << "]";
}

int main(){
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;
    vector<int> inp(n);
    cout << "Enter " << n << " elements in to the array " << endl;
    for (int i = 0; i < n; i++){
        cin >> inp[i];
    }

    cout << "Using recursion " << endl;
    vector<vector<int>>ans1 = solve(inp, n);
    print(ans1);
}