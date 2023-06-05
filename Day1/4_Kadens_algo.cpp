/*
    Kadane’s Algorithm : Maximum Subarray Sum in an Array
    Problem Statement: Given an integer array arr, find the contiguous subarray (containing at least one number) which
    has the largest sum and returns its sum and prints the subarray.

    Example 1:
    Input: arr = [-2,1,-3,4,-1,2,1,-5,4]
    Output: 6
    Explanation: [4,-1,2,1] has the largest sum = 6.

    Examples 2:
    Input: arr = [1]
    Output: 1
    Explanation: Array has only one element and which is giving positive sum of 1.


    Brute force approach :
        generate all the possible sub-arrays and sum them get the max out of all the summation
        Time complexity : O(N^3)
        Space complexity : O(1)

    Better approach :
        by maintaining prefix sum we can reduce the time complexity
        Time complexity: O(N^2)
        Space complexity : O(1)

    Optimal :
        Using kadens algorithm
        if sum <= 0 then make the sum =0; and update the maxi max(maxi, sum)

        Time complexity : O(N)
        Space complexity : O(1)
*/


#include<bits/stdc++.h>
using namespace std;

int brute(vector<int>vec, int n){
    int maxi = INT_MIN;
    for(int i=0; i<n; i++){
        for (int j = i; j < n; j++){
            int sum = 0;
            for (int k = i; k <= j; k++){
                sum += vec[k];
            }
            maxi = max(sum, maxi);
        }
    }
    return maxi;
}


int better(vector<int>vec, int n){
    int maxi = INT_MIN;
    for(int i=0; i<n; i++){
        int sum = 0;
        for (int j = i; j < n; j++){
            sum += vec[j];
            maxi = max(maxi, sum);
        }
    }
    return maxi;
}



int optimal(vector<int>vec, int n){
    int maxi = INT_MIN;
    int sum = 0;
    for (int i = 0; i<n; i++){
        sum += vec[i];
        // maxi = max(sum, maxi);
        if(sum>maxi)
            maxi = sum;
        if(sum <=0)
            sum = 0;
    }
    return maxi;
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
    cout << "Brute force approach :"<<brute(vec, n)<<endl;
    cout << "Better approach : " << better(vec, n) << endl;
    cout << "Optimal approach : "<<optimal(vec, n)<<endl;
    return 0;
}