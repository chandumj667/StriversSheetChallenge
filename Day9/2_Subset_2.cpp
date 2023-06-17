/*
    Subset – II | Print all the Unique Subsets
    Problem Statement: Given an array of integers that may contain duplicates the task is to return all possible subsets. Return only unique subsets and they can be in any order.

    Input: array[] = [1,2,2]
    Output: [ [ ],[1],[1,2],[1,2,2],[2],[2,2] ]
    Explanation: We can have subsets ranging from  length 0 to 3. which are listed above. Also the subset [1,2] appears twice but is printed only once as we require only unique subsets.

    Input: array[] = [1]
    Output: [ [ ], [1] ]
    Explanation: Only two unique subsets are available

    Brute force approach:
        we can get the every subset but we have to take care of the duplicate elements
        for that we use set to remove duplicates

        Time complexity: O(2^n)+O(m log n)
        Space complexity: O(2^n)+O(2^n)
    
    Optimal approach:
        sort the array
        by taking the index value and maintaining a data structure with size s and increment every recursive call  s+1 and avoiding the duplicate  

        index i = i-(n-1) to avoid duplicates

        Time complexity : O(2^n *n)
        Space complexity: O(2^n * k)


*/


#include<bits/stdc++.h>
using namespace std;


void print(vector<vector<int>>&ans){
    cout << "Unique subsets are: " << endl;
    cout << "[]";
    for(auto i:ans){
        for(auto r:i){
            cout << r << " ";
        }
        cout << endl;
    }
}

void solve(int ind, vector<int>&vec, vector<int>&ls, vector<vector<int>>&ans){
    ans.push_back(ls);
    for (int i = ind; i < vec.size(); i++){
        if(i!= ind && vec[i] == vec[i-1])
            continue;
        ls.push_back(vec[i]);
        solve(i + 1, vec, ls, ans);
        ls.pop_back();
    }
}

vector<vector<int>>output(vector<int>&vec){
    vector<vector<int>> ans;
    vector<int> ls;
    sort(vec.begin(), vec.end());
    solve(0, vec, ls, ans);
    return ans;
}


int main(){
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;
    vector<int> vec(n);
    cout << "Enter " << n << " elements in to the array :" << endl;
    for (int i = 0; i<n; i++){
        cin >> vec[i];
    }
    // sort(vec.begin(), vec.end());
    // vector<vector<int>> ans=solve(vec);
    vector<vector<int>> ans = output(vec);
    print(ans);
}