/*
    Combination Sum – 1

    Problem Statement:
    Given an array of distinct integers and a target, you have to return the list of all unique combinations where the chosen numbers sum to target. You may return the combinations in any order.
    The same number may be chosen from the given array an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
    It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

    Example 1:
    Input: array = [2,3,6,7], target = 7
    Output: [[2,2,3],[7]]
    Explanation: 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
                7 is a candidate, and 7 = 7.
                These are the only two combinations.

    Example 2:
    Input: array = [2], target = 1
    Output: []
    Explanation: No combination is possible.

    Approach:
        Using recursion we can take the same element multiple times and we take them until target becomes zero if not we move the index 
        if the index reaches end we return or if the target becomes zero we return the data-structure we store all the combinations

        Time complexity : O(2^k *k)
        Space complexity : Based on the no.of combinations
                            O(k*n)
*/


#include<bits/stdc++.h>
using namespace std;


void print(vector<vector<int>>&ans){
    cout << "All combinations possible for the target are: " << endl;
    cout << "[ ";
    cout << endl;
    for(auto i:ans){
        cout << "     [";
        for(auto c:i){
            cout << c << " ";
        }
        cout << "]";
        cout << endl;
    }
    cout << "]";
}

void result(int ind, vector<int>&vec, int target, vector<vector<int>>&ans, vector<int>&ls){
    if(ind == vec.size()){
        if(target == 0){
            ans.push_back(ls);
        }
        return;
    }

    if(vec[ind] <= target){
        ls.push_back(vec[ind]);
        result(ind, vec, target - vec[ind], ans, ls);
        ls.pop_back();
    }
    result(ind + 1, vec, target, ans, ls);
}

vector<vector<int>> solve(vector<int> &vec, int target){
    vector<vector<int>> ans;
    vector<int> ls;
    result(0, vec, target, ans, ls);
    return ans;
}

int main(){
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;
    vector<int> vec(n);
    cout << "Enter " << n << " elements in to the array : " << endl;
    for (int i = 0; i < n; i++){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    int target;
    cout << "Enter the target value : ";
    cin >> target;
    vector<vector<int>> ans = solve(vec, target);
    print(ans);
    return 0;
}