/*
    Subset Sum : Sum of all Subsets
    Problem Statement: Given an array print all the sum of the subset generated from it, in the increasing order.


    Input: N = 3, arr[] = {5,2,1}
    Output: 0,1,2,3,5,6,7,8
    Explanation: We have to find all the subset’s sum and print them.in this case the generated subsets are [ [], [1], [2], [2,1], [5], [5,1], [5,2]. [5,2,1],so the sums we get will be  0,1,2,3,5,6,7,8

    Input: N=3,arr[]= {3,1,2}
    Output: 0,1,2,3,3,4,5,6
    Explanation: We have to find all the subset’s sum and print them.in this case the generated subsets are [ [], [1], [2], [2,1], [3], [3,1], [3,2]. [3,2,1],so the sums we get will be  0,1,2,3,3,4,5,6

    Approach :
        On every index you have two options either to select the element
        So when we have two options take it and use it anf get the result and check with others too

        for each element take it  or leave it and if taken add it to the sum and increment the index if index reaches to the n then return sum

        Time complexity : O(2^n) + O(2^n log 2^n)
        Space complexity: O(2^n)
*/

#include<bits/stdc++.h>
using namespace std;


void solve(vector<int>&vec, int i, int sum, int n, vector<int>&subset){
    if(i == n){
        subset.push_back(sum);
        return;
    }
    solve(vec, i + 1, sum + vec[i], n, subset);
    solve(vec, i + 1, sum, n, subset);
}   

int main(){
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;
    vector<int> vec(n);
    cout << "Enter " << n << " elements in to the array : " << endl;
    for (int i = 0; i < n; i++){
        cin >> vec[i];
    }
    int sum = 0;
    vector<int> subset;
    solve(vec, 0, sum, n, subset);
    sort(subset.begin(), subset.end());
    for(auto i:subset){
        cout << i << " ";
    }
    return 0;
}