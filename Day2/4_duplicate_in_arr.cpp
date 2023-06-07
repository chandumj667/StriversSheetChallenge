/*
    Find the duplicate in an array of N+1 integers
    Problem Statement: Given an array of N + 1 size, where each element is between 1 and N. Assuming there is only one duplicate number, your task is to find the duplicate number.

    Example 1:
    Input: arr=[1,3,4,2,2]
    Output: 2
    Explanation: Since 2 is the duplicate number the answer will be 2.

    Example 2:
    Input: [3,1,3,4,2]
    Output:3
    Explanation: Since 3 is the duplicate number the answer will be 3

    Brute force approach  :
        using sorting technique and comparing adjacent elements we get the duplicate element
        Time complexity : O(n logn);
        space complexity : O(1)

    better approach :
        using an hashmap by counting the frequency of elements and if any get more than 1 then return it as as duplicate
        Time complexity: O(n);
        Space complexity : O(n);

    Optimal approach : 
        using linked list cycle  detection method ny using two points as slow and fast
        slow goes one step while fast moves two steps
        Time complexity: O(n)
        Space complexity : O(1)
*/

#include<bits/stdc++.h>
using namespace std;



int brute(vector<int>vec, int n){
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n; i++){
        if(vec[i] == vec[i+1]){
            return vec[i];
        }
    }
    return -1;
}


int better(vector<int>vec, int n){
    unordered_map<int, int>ump;
    for (int i = 0; i<n; i++){
        ump[vec[i]]++;
    }
    for(auto i: ump){
        if(i.second>1)
            return i.first;
    }
    return -1;
}


int optimal(vector<int>vec, int n){
    int slow = vec[0];
    int fast = vec[0];
    do{
        slow = vec[slow];
        fast = vec[vec[fast]];
    } while (slow != fast);

    slow = vec[0];
    while(slow != fast){
        slow = vec[slow];
        fast = vec[fast];
    }
    return slow;
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
    cout << "Brute force approach" << endl;
    cout<<brute(vec, n)<<endl;
    cout << "better approach " << endl;
    cout << better(vec, n) << endl;
    cout << "Optimal approach " << endl;
    cout << optimal(vec, n) << endl;

    return 0;
}