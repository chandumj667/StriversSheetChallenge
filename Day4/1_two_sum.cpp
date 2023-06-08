/*
    Two Sum : Check if a pair with given sum exists in Array
    Problem Statement: Given an array of integers arr[] and an integer target.

    1st variant: Return YES if there exist two numbers such that their sum is equal to the target. Otherwise, return NO.

    2nd variant: Return indices of the two numbers such that their sum is equal to the target. Otherwise, we will return {-1, -1}.

    Note: You are not allowed to use the same element twice. Example: If the target is equal to 6 and num[1] = 3, then nums[1] + nums[1] = target is not a solution.


    Example 1:
    Input Format: N = 5, arr[] = {2,6,5,8,11}, target = 14
    Result: YES (for 1st variant)
        [1, 3] (for 2nd variant)
    Explanation: arr[1] + arr[3] = 14. So, the answer is “YES” for the first variant and [1, 3] for 2nd variant.

    Example 2:
    Input Format: N = 5, arr[] = {2,6,5,8,11}, target = 15
    Result: NO (for 1st variant)
        [-1, -1] (for 2nd variant)
    Explanation: There exist no such two numbers whose sum is equal to the target.

    Brute force approach :
        using nested loops and checking each pair sum as arr[i]+arr[j] == target
        if yes then return  those two values
        Time complexity : O(N^2)
        Space complexity : O(1)

    Better approach :
        using hashmap , as we have the current value and target value with us 
        let a == value1  and b == value2 
        then a+b = target
        we have current value let it be (a)
        therefore a+b = target ==> b= target - a
        find whether b is present in hashmap or not if present return both the values if not add the current element in to the hashmap

        Time complexity : O(N)
        Space complexity : O(N)
*/


#include<bits/stdc++.h>
using namespace std;


void print(vector<int>ans){
    for(auto i:ans){
        cout << i << " ";
    }
    cout << endl;
}

void brute(vector<int>vec, int n, int t){
    cout << "Brute force approach ";
    vector<int> ans;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if((i!=j) && (vec[i]+vec[j] == t)){
                ans.push_back(vec[i]);
                ans.push_back(vec[j]);
                print(ans);
                return;
            }
        }
    }
    ans.push_back(-1);
    ans.push_back(-1);
    print(ans);
    
}




int main(){
    int n;
    cout<<"Enter the size of the array ";
    cin >> n;
    vector<int> vec(n);
    cout << "Enter " << n << " elements in to the array " << endl;
    for (int i = 0; i < n; i++){
        cin >> vec[i];
    }
    int t;
    cout << "Enter the target element ";
    cin >> t;
    brute(vec, n, t);
}