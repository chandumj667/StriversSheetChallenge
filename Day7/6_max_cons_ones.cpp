/*
    Count Maximum Consecutive One’s in the array
    Problem Statement: Given an array that contains only 1 and 0 return the count of maximum consecutive ones in the array.

    Example 1:
    Input: prices = {1, 1, 0, 1, 1, 1}
    Output: 3
    Explanation: There are two consecutive 1’s and three consecutive 1’s in the array out of which maximum is 3.

    Input: prices = {1, 0, 1, 1, 0, 1}
    Output: 2
    Explanation: There are two consecutive 1's in the array.

    Approach:
        traverse the array and maintain a variable of maxi  and count
        if vec[i] == 1 then increment count and maxi = max(maxi, count)
        else count =0;

        Time complexity: O(n)
        Space complexity : O(1)

*/


#include<bits/stdc++.h>
using namespace std;


int solve(vector<int>vec, int n){
    int cnt = 0;
    int maxi = 0;
    for(auto i: vec){
        if(i ==1){
            cnt++;
        }
        else{
            cnt = 0;
        }
        maxi = max(maxi, cnt);
    }
    return maxi;
}

int main(){
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;
    vector<int>vec(n);
    cout << "Enter " << n << " elements in to the array " << endl;
    for (int i = 0; i < n; i++){
        cin >> vec[i];
    }
    cout << "The Maximum consecutive ones are : " << solve(vec, n) << endl;
    return 0;
}