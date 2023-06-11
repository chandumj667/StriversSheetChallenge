/*
    Longest Consecutive Sequence in an Array
    Problem Statement: You are given an array of ‘N’ integers. You need to find the length of the longest sequence which contains the consecutive elements.


    Example 1:
    Input: [100, 200, 1, 3, 2, 4]
    Output: 4
    Explanation: The longest consecutive subsequence is 1, 2, 3, and 4.

    Example 2:
    Input: [3, 8, 5, 7, 6]
    Output: 4
    Explanation: The longest consecutive subsequence is 5, 6, 7, and 8.


    Brute force approach :
        Sort the array and check the current element ans previous elements if they are consecutive then increment the length variable
        return the maximum length of consecutive elements we have

        Time Complexity : O(n logn) + o(n);
        Space Complexity : O(1);

    Optimal approach :
        Using hash-set insert all the elements in to the hash-set 
        then check for each element its prev consecutive present in hash-set or not 
        if not then check next consecutive if present then increment the count 

        Time Complexity : O(n)+O(n)+O(n)
        Space Complexity : O(n)
*/


#include<bits/stdc++.h>
using namespace std;


int brute(vector<int>vec, int n){
    sort(vec.begin(), vec.end());
    int count = 1;
    int ans = 0;
    for (int i = 1; i < n; i++){
        if(vec[i]-1 == vec[i-1]){
            count++;
        }
        else{
            count = 1;
        }
        ans = max(ans, count);
    }
    return ans;
}


int optimal(vector<int>vec, int n){
    set<int> st;
    for(auto i:vec){
        st.insert(i);
    }
    int cnt = 0;
    for(auto i:vec){
        if(!st.count(i-1)){
            int num = i;
            int length = 1;
            while(st.count(num+1)){
                num += 1;
                length += 1;
            }
            cnt = max(cnt, length);
        }
    }
    return cnt;
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
    cout << "Optimal approach : " << optimal(vec, n) << endl;
    return 0;

}