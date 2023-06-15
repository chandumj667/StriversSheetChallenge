/*
    Remove Duplicates in-place from Sorted Array
    Problem Statement: Given an integer array sorted in non-decreasing order, remove the duplicates in place such that each unique element appears only once. The relative order of the elements should be kept the same.

    If there are k elements after removing the duplicates, then the first k elements of the array should hold the final result. It does not matter what you leave beyond the first k elements.
    Note: Return k after placing the final result in the first k slots of the array.

    Example 1:
    Input: arr[1,1,2,2,2,3,3]
    Output: arr[1,2,3,_,_,_,_]
    Explanation: Total number of unique elements are 3, i.e[1,2,3] and Therefore return 3 after assigning [1,2,3] in the beginning of the array.

    Example 2:
    Input: arr[1,1,1,2,2,3,3,3,3,4,4]
    Output: arr[1,2,3,4,_,_,_,_,_,_,_]
    Explanation: Total number of unique elements are 4, i.e[1,2,3,4] and Therefore return 4 after assigning [1,2,3,4] in the beginning of the array.


    Brute force approach :
        Using set data structure gives the unique element

        Time complexity: O(n)
        Space complexity: O(n)

    Optimal approach:
        using two pointers approach
        l =0; and h =1;
        if(vec[l] == vec[h]){
            h++;
        }
        else{
            l++;
            swap(vec[l], vec[h]);
        }
        return l;

        Time complexity : O(n)
        Space complexity: O(1)
*/



#include<bits/stdc++.h>
using namespace std;

int brute(vector<int>vec, int n){
    set<int>st;
    for(auto i:vec){
        st.insert(i);
    }
    return st.size();
}

int optimal(vector<int> vec, int n){
    int l =0;
    int h = 0;
    while(h<n){
        if(vec[l] != vec[h]){
            l++;
            swap(vec[l], vec[h]);
        }
        h++;
    }
    return l+1;
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
    cout << "Using Brute force approach : " << brute(vec, n) << endl;
    cout << "Using optimal approach : " << optimal(vec, n) << endl;
    return 0;
}