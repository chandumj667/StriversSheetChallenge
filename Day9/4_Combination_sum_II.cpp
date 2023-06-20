/*
    Combination Sum II – Find all unique combinations
    In this article we will solve the most asked interview question “Combination Sum II – Find all unique combinations”.

    Problem Statement: Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target. Each number in candidates may only be used once in the combination.
    Note: The solution set must not contain duplicate combinations.

    Example 1:
    Input: candidates = [10,1,2,7,6,1,5], target = 8
    Output:
    [
        [1,1,6],
        [1,2,5],
        [1,7],
        [2,6]
    ]
    Explanation: These are the unique combinations whose sum is equal to target.

    Example 2:
    Input: candidates = [2,5,2,1,2], target = 5
    Output: 
    [
        [1,2,2],
        [5]
    ]
    Explanation: These are the unique combinations whose sum is equal to target.

    Approach:
        Same as the combination sum 1 but here we are not taking the duplicate combinations and skip the duplicate values in the vec 

        Time complexity: O(2^n *k)
        Space complexity: O(k*x)


*/


#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>>&ans){
    cout << "\nUnique combinations of target : " << endl;
    cout << "[" << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "   [";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "]";
        cout << endl;
    }
    cout << "]";
}


void combinations(int ind, int target, vector<int>&vec, vector<vector<int>>&ans, vector<int>&ds){
    if(target == 0){
        ans.push_back(ds);
        return;
    }
    for (int i = ind; i < vec.size(); i++){
        if(i>ind && vec[i] == vec[i-1])
            continue;
        if(vec[i] > target)
            break;

        ds.push_back(vec[i]);
        combinations(i + 1, target - vec[i], vec, ans, ds);
        ds.pop_back();
    }
}

vector<vector<int>>solve(vector<int>&vec, int target){
    sort(vec.begin(), vec.end());
    vector<vector<int>> ans;
    vector<int> ds;
    combinations(0, target, vec, ans, ds);
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

    int target;
    cout << "Enter the target value  : ";
    cin >> target;

    vector<vector<int>> ans = solve(vec, target);
    print(ans);
}