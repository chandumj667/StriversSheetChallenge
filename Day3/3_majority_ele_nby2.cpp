/*
    Find the Majority Element that occurs more than N/2 times
    Problem Statement: Given an array of N integers, write a program to return an element that occurs more than N/2 times in the given array. You may consider that such an element always exists in the array.

    Example 1:
    Input Format: N = 3, nums[] = {3,2,3}
    Result: 3
    Explanation: When we just count the occurrences of each number and compare with half of the size of the array, you will get 3 for the above solution.

    Example 2:
    Input Format:  N = 7, nums[] = {2,2,1,1,1,2,2}
    Result: 2
    Explanation: After counting the number of times each element appears and comparing it with half of array size, we get 2 as result.

    Example 3:
    Input Format:  N = 10, nums[] = {4,4,2,4,3,4,4,3,2,4}
    Result: 4


    Brute force approach :
        nested loop for each element and count the occurrences and if any element have the count >= n/2 then return it
        Time complexity : O(N^2)
        Space complexity : O(1)

    Better approach :
        Using hashmap or hash-array
        check the i.second>=n/2 then return i.first
        Time complexity : O(n)
        Space complexity : O(n)

    Optimal approach :
        moore's voting algorithm
        maintaining a count and ele variable
        if count ==0 then assign ele = vec[i]
        if vec[i] == ele then count++;
        else count--;

        at last the element which is in ele is the majority element

        Time complexity : O(n)
        Space complexity : O(1)
*/

#include<bits/stdc++.h>
using namespace std;



int brute(vector<int>vec, int n){
    for (int i = 0; i<n; i++){
        int count = 1;
        for (int j = i+1; j < n; j++){
            if(vec[i] == vec[j]){
                count++;
                if(count > n/2)
                    return vec[j];
            }
        }
    }
    return -1;
}


int better(vector<int>vec, int n){
    unordered_map<int, int>ump;
    for (int i = 0; i < n; i++){
        ump[vec[i]]++;
    }
    for(auto i:ump){
        if(i.second > n/2){
            return i.first;
        }
    }
    return -1;
}


int optimal(vector<int>vec, int n){
    int count = 0;
    int ele;
    for (int i = 0; i < n; i++){
        if(count == 0){
            ele = vec[i];
            count = 1;
        }
        else if(vec[i] == ele){
            count++;
        }
        else {
            count--;
        }
    }
    int cntr = 0;
    for (int i = 0; i<n; i++){
        if(vec[i] == ele){
            cntr++;
        }
    }
    if(cntr > n/2)
        return ele;
    return -1;
}

int main(){
    int n;
    cout << "Enter the size of the array ";
    cin >> n;
    vector<int> vec(n);
    cout << "Enter " << n << " elements in to the array " << endl;
    for (int i = 0; i < n; i++){
        cin >> vec[i];
    }
    cout << "Brute force approach : " << brute(vec, n) << endl;
    cout << "Better approach : " << better(vec, n)<<endl;
    cout << "optimal approach : " << optimal(vec, n) << endl;
    return 0;
}