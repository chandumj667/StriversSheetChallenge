/*
    Length of the longest sub-array with zero Sum
    Problem Statement: Given an array containing both positive and negative integers, we have to find the length of the longest sub-array with the sum of all elements equal to zero.

    Example 1:
    Input Format: N = 6, array[] = {9, -3, 3, -1, 6, -5}
    Result: 5
    Explanation: The following sub-arrays sum to zero:
    {-3, 3} , {-1, 6, -5}, {-3, 3, -1, 6, -5}
    Since we require the length of the longest sub-array, our answer is 5!
    
    Example 2:
    Input Format: N = 8, array[] = {6, -2, 2, -8, 1, 7, 4, -10}
    Result: 8
    Sub-arrays with sum 0 : {-2, 2}, {-8, 1, 7}, {-2, 2, -8, 1, 7}, {6, -2, 2, -8, 1, 7, 4, -10}
    Length of longest sub-array = 8
    
    Example 3:
    Input Format: N = 3, array[] = {1, 0, -5}
    Result: 1
    Sub-array : {0}
    Length of longest sub-array = 1
    
    Example 4:
    Input Format: N = 5, array[] = {1, 3, -5, 6, -2}
    Result: 0
    Sub-array: There is no sub-array that sums to zero

    Brute force approach :

*/

#include<bits/stdc++.h>
using namespace std;


// int brute(vector<int>vec, int n){
//     int ans = 0;
//     for (int i = 0; i < n; i++){
//         for (int j = i + 1; j < n;  j++){
//             int sum = 0;
//             for (int k = i; k <= j; k++){
//                 sum += vec[i];
//             }
//             if(sum == 0){
//                 ans = max(ans, i - j+1);
//             }
//         }
//     }
//     return ans;
// }

// int better(vector<int>vec, int n){
//     int ans = 0;
//     for (int i = 0; i < n; i++){
//         int sum =0;
//         for (int j = 0; j < n; j++){
//             sum += vec[i];
//             if(sum ==0){
//                 ans = max(ans, j - i + 1);
//             }
//         }
//     }
//     return ans;
// }

int optimal(vector<int>vec, int n){
    unordered_map<int, int> ump;
    int sum =0;
    int ans = 0;
    for (int i = 0; i < n; i++){
        sum += vec[i];
        if(sum ==0){
            ans = i + 1;
        }
        else{
            if(ump.find(sum)!= ump.end()){
                ans = max(ans, i - ump[sum]);
            }
            else{
                ump[sum] = i;
            }
        }
    }
    return ans;
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
    cout << "Optimal approach : " << optimal(vec, n) << endl;
    return 0;
}