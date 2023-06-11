/*
    Count the number of sub-arrays with given xor K
    Problem Statement: Given an array of integers A and an integer B. Find the total number of sub-arrays having bitwise XOR of all elements equal to k.
    Pre-requisite: Find the number of sub-arrays with the sum K

    Example 1:
    Input Format: A = [4, 2, 2, 6, 4] , k = 6
    Result: 4
    Explanation: The sub-arrays having XOR of their elements as 6 are  [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]

    Example 2:
    Input Format: A = [5, 6, 7, 8, 9], k = 5
    Result: 2
    Explanation: The sub-arrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]


    Brute force approach :
        Generate all sub-array and check the condition if teh sub-array xor is equal to k then increment the count

        Time Complexity : O(n^3)
        Space complexity : O(1)

    Better approach : 
        maintain a prefix xor for the brute force approach that reduces the time complexity 

        Time Complexity: O(n^2)
        Space complexity : O(1)

    Optimal approach: 
        using xor for each element and xor the result with k we get an ans check it in the hash-map if it is present  add output to its count 

        Time complexity : o(n)
        Space complexity : O(n)

*/


#include<bits/stdc++.h>
using namespace std;

int brute(vector<int>vec, int n, int k){
    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            int xr = 0;
            for (int l = i; l <= j; l++){
                xr = xr ^ vec[l];
            }
            if(xr == k){
                ans++;
            }
        }
    }
    return ans;
}

int better(vector<int> vec, int n, int k){
    int ans = 0;
    for (int i = 0; i < n; i++){
        int xr = 0;
        for (int j = i; j < n; j++){
            xr = xr ^ vec[j];
        }
        if (xr == k){
            ans++;
        }
    }
    return ans;
}


int optimal(vector<int>vec, int n, int k){
    int a = 0;
    int count = 0;
    map<int, int> mp;
    mp[a]++;
    for (int i = 0; i < n; i++){
        a = a ^ vec[i];
        int b = a ^ k;
        count += mp[b];
        mp[a]++;
    }
    return count;
}


int main(){
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;
    vector<int> vec(n);
    cout << "Enter " << n << " elements in to the array " << endl;
    for (int i = 0; i < n; i++){
        cin >> vec[i];
    }
    int k;
    cout << "Enter the xor(K) value : ";
    cin >> k;
    cout << "Brute force approach : " << brute(vec, n, k)<<endl;
    cout << "Better approach : " << brute(vec, n, k)<<endl;
    cout << "Optimal approach : " << brute(vec, n, k) << endl;
    return 0;
}