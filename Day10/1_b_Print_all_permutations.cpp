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


    Approach 2:
        using a logic of swap the elements and call the recursive function and store them in a list of list

        Time complexity : O(n! * n)
        Space complexity: O(n!)

*/


#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>>&ans){
    cout << "Using approach 2" << endl;
    cout << "[" << endl;
    for(auto r:ans){
        cout << "    [";
        for(auto i:r){
            cout << i << " ";
        }
        cout << "]";
        cout << endl;
    }

}


void fun(int ind, vector<int>&vec, vector<vector<int>>&ans){
    if(ind == vec.size()){
        ans.push_back(vec);
        return;
    }
    for (int i = ind; i < vec.size(); i++){
        swap(vec[ind], vec[i]);
        fun(ind + 1, vec, ans);
        swap(vec[ind], vec[i]);
    }
}

vector<vector<int>>solve(vector<int>&vec, int n){
    vector<vector<int>> ans;
    fun(0, vec, ans);
    return ans;
}

int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin>>n;
    vector<int> vec(n);
    cout << "Enter " << n << " elements in to the array : " << endl;
    for (int i = 0; i < n; i++){
        cin >> vec[i];
    }
    vector<vector<int>> ans = solve(vec, n);
    print(ans);
}