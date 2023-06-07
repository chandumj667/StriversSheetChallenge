/*
    Merge Overlapping Sub-intervals
    Problem Statement: Given an array of intervals, merge all the overlapping intervals and return an array of non-overlapping intervals.

    Example 1:
    Input: intervals=[[1,3],[2,6],[8,10],[15,18]]
    Output: [[1,6],[8,10],[15,18]]
    Explanation: Since intervals [1,3] and [2,6] are overlapping we can merge them to form [1,6]
    intervals.

    Example 2:
    Input: [[1,4],[4,5]]
    Output: [[1,5]]
    Explanation: Since intervals [1,4] and [4,5] are overlapping we can merge them to form [1,5].

    brute force approach :
        sort the given intervals by first element
        and traverse the elements check if the interval is in the range of the first one if yes then update the boundary to max of them if not break and push the new interval in to ans
        Time complexity : O(N LogN) + O(2N)
        Space complexity ; O(N)

    Brute force :
        doing the same in single traverse:
        Time Complexity : O(N logN)+O(N)
        Space complexity : O(N)
*/


#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>>vec, int n){
    for (auto i:vec){
        for(auto j:i){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void brute(vector<vector<int>>vec, int n){
    sort(vec.begin(), vec.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++){
        int st = vec[i][0];
        int end = vec[i][1];
        if(!ans.empty() && end<=ans.back()[1]){
            continue;
        }
        for (int j = i + 1; j < n; j++){
            if(vec[j][0] <= end){
                end = max(end, vec[j][1]);
            }
            else {
                break;
            }
        }
        ans.push_back({st, end});
    }
    cout << "Brute force approach " << endl;
    print(ans, n);
}

void optimal(vector<vector<int>>vec, int n){
    sort(vec.begin(), vec.end());
    vector<vector<int>>ans;
    for (int i = 0; i<n; i++){
        if(ans.empty() || vec[i][0]>ans.back()[1]){
            ans.push_back(vec[i]);
        }
        else{
            ans.back()[1] = max(ans.back()[1], vec[i][1]);
        }
    }
    cout<<"Optimal approach "<<endl;
    print(ans, n);
}



int main(){
    int n;
    cout << "Enter the size of the container ";
    cin>>n;
    vector<vector<int>> vec;
    cout << "Enter " << n << " pairs in to the container " << endl;
    for (int i = 0; i<n; i++){
        int a;
        int b;
        cin >> a >> b;
        vec.push_back({a, b});
    }
    brute(vec, n);
    optimal(vec, n);
}