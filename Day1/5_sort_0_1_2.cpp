/*
    Sort an array of 0s, 1s and 2s
    Problem Statement: Given an array consisting of only 0s, 1s, and 2s. Write a program to in-place sort the array without using inbuilt sort functions. ( Expected: Single pass-O(N) and constant space)

    Examples
    Input: nums = [2,0,2,1,1,0]
    Output: [0,0,1,1,2,2]

    Input: nums = [2,0,1]
    Output: [0,1,2]

    Input: nums = [0]
    Output: [0]

    Brute force approach :
        sort the array then it is easily get the array
        Time complexity : O(N log N)
        Space complexity : O(1)

    Better approach :
        using variable to cunt the occurrence of each one as zero_count, one_count, two_count
        then create a new array and using the each count variable initialize the new array with the values
        Time Complexity: O(N)
        Space complexity : O(N)

    Optimal approach:
        using three pointers
        let == 0, m =0, e =n-1;
        if(arr[m] == 0) swap(arr[l++], arr[m++]);
        if(arr[i] == 1)m++;
        if(arr[m] == 2) swap(arr[m], arr[h--])
        Time complexity : O(N)
        Space complexity : O(1)
    return the array:
*/


#include<bits/stdc++.h>
using namespace std;

void print(vector<int>vec, int n){
    for (int i = 0; i < n; i++){
        cout << vec[i] << " ";
    }
    cout << endl;
}


void brute(vector<int>vec, int n){
    sort(vec.begin(), vec.end());
    print(vec, n);
}

void better(vector<int>vec, int n){
    // we can use hashmap instead of this entire counting code
    int zeros = 0;
    int ones = 0;
    int twos = 0;
    for (int i = 0; i<n; i++){
        if(vec[i]==0)
            zeros++;
        else if(vec[i] == 1)
            ones++;
        else
            twos++;
    }
    for(int i=0; i<zeros; i++){
        vec[i] = 0;
    }
    for (int i = zeros; i<ones+zeros; i++){
        vec[i] = 1;
    }
    for (int i = zeros + ones; i < zeros + ones + twos; i++){
        vec[i] = 2;
    }
        print(vec, n);
}


void optimal(vector<int>vec, int n){
    int l =0;
    int m = 0;
    int h = n - 1;
    while(m<=h){
        if(vec[m] == 1){
            m++;
        }
        else if(vec[m]==0){
            swap(vec[l++], vec[m++]);
        }
        else{
            swap(vec[h--], vec[m]);
        }
    }
    print(vec, n);
}

int main(){
    int n;
    cout << "Enter the size of the array ";
    cin>>n;
    vector<int> vec(n);
    cout << "enter " << n << " elements in to the array "<<endl;
    for(int i=0; i<n; i++){
        cin >> vec[i];
    }

    cout << "Brute force approach : ";
    brute(vec, n);
    cout << "Better approach : ";
    better(vec, n);
    cout << "Optimal approach : ";
    optimal(vec, n);
    return 0;
}