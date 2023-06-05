/*
    next_permutation : find next lexicographically greater permutation
    Problem Statement: Given an array Arr[] of integers, rearrange the numbers of the given array into the lexicographically next greater permutation of numbers.

    If such an arrangement is not possible, it must rearrange to the lowest possible order (i.e., sorted in ascending order).

    Examples
    Example 1 :

    Input format: Arr[] = {1,3,2}
    Output: Arr[] = {2,1,3}
    Explanation: All permutations of {1,2,3} are {{1,2,3} , {1,3,2}, {2,13} , {2,3,1} , {3,1,2} , {3,2,1}}. So, the next permutation just after {1,3,2} is {2,1,3}.
    Example 2:

    Input format: Arr[] = {3,2,1}
    Output: Arr[] = {1,2,3}
    Explanation: As we see all permutations of {1,2,3}, we find {3,2,1} at the last position. So, we have to return the topmost permutation.

    Brute force approach :
        generate all the possible permutations in a sorted order
        store them in a list and check the given number with all the number and if any match then get the next index
        return it
        if the number is the last one in the list return the first number in the list

        Time complexity : O(N! * N)
        Space complexity : O(N^2)

    Better approach :
        C++ STL next_permutation(vec.begin(), vec.end());
        return vec;

    Optimal approach:
        implement the STL algorithm
        take the ind as -1;
        traverse from n-2 to 0 and compare the ith and i+1th element
        if arr[i]<arr[i+1] then store the ind as i;
        check if ind ==-1 reverse the complete arr and return it if not
        traverse the array from n-1 to ind
        if arr[i]<arr[ind] then swap them and reverse the array from arr.begin()+ind+1 to arr.end()
        then return the array

        Time complexity :O(N)
        Space compleXity : O(1)
*/


#include<bits/stdc++.h>
using namespace std;

vector<int>nextp(vector<int>vec, int n){
    int in = -1;
    for (int i = n - 2; i >= 0; i--){
        if(vec[i]<vec[i+1]){
            in = i;
            break;
        }
    }
    if(in ==-1){
        reverse(vec.begin(), vec.end());
        return vec;
    }
    for (int i = n - 1; i >in; i--){
        if(vec[i]>vec[in]){
            swap(vec[in], vec[i]);
            break;
        }
    }
    reverse(vec.begin() + in + 1, vec.end());
    return vec;
}

int main(){
    int n;
    cout<<"Enter the size of the array ";
    cin>>n;
    vector<int>vec(n);
    cout << "Enter " << n << " elements in to the array" << endl;
    for (int i = 0; i < n; i++){
        cin >> vec[i];
    }
    vector<int> ans = nextp(vec, n);
    for (int i = 0; i<n; i++){
        cout << ans[i] << " ";
    }
    return 0;
}