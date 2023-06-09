/*
    4 Sum | Find Quads that add up to a target value
    Problem Statement: Given an array of N integers, your task is to find unique quads that add up to give a target value. In short, you need to return an array of all the unique quadruplets [arr[a], arr[b], arr[c], arr[d]] such that their sum is equal to a given target.

    Pre-req: 3-sum problem and 2-sum problem

    Note:
    0 <= a, b, c, d < n
    a, b, c, and d are distinct.
    arr[a] + arr[b] + arr[c] + arr[d] == target


    Example 1:
    Input Format: arr[] = [1,0,-1,0,-2,2], target = 0
    Result: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
    Explanation: We have to find unique quadruplets from the array such that the sum of those elements is equal to the target sum given that is 0. The result obtained is such that the sum of the quadruplets yields 0.

    Example 2:
    Input Format: arr[] = [4,3,3,4,4,2,1,2,1,1], target = 9
    Result: [[1,1,3,4],[1,2,2,4],[1,2,3,3]]
    Explanation: The sum of all the quadruplets is equal to the target i.e. 9.


    Brute force approach :
        using four inner loops for each combination
        Time complexity : O(n^4)
        Space complexity : O(no.of quadrants)

    Better approach :
        using an hash-set 
        Time complexity : O(n^3) * O(log n)
        Space complexity  : O(n)+O(no.of quadrants)

    Optimal approach:
        we use two loops for the fixed values i and j from 0 to n ans i+1 to  n respectively
        and we run another two pointer k and l from j+1 and n-1 respectively
        if the k and l got terminated we increment the j and if j got terminated we increment the i 

        Time complexity : O(n^3)
        Space complexity : O(no.of quadrants)
*/


#include<bits/stdc++.h>
using namespace std;


void print(vector<vector<int>>vec){
    for(auto r:vec){
        cout << "[ ";
        for(auto e:r){
            cout << e << " ";
        }
        cout << " ]";
        cout << endl;
    }
    cout << endl;
}


// Brute force approach

void brute(vector<int> &vec, int n, int t){
    set<vector<int>> s;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            for (int k = j + 1; k < n; k++){
                for (int l = k + 1; l < n; l++){
                    long long sum = vec[i];
                    sum += vec[j];
                    sum += vec[k];
                    sum += vec[l];
                    if (sum == t){
                        vector<int> tmp = {vec[i], vec[j], vec[k], vec[l]};
                        sort(tmp.begin(), tmp.end());
                        s.insert(tmp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(s.begin(), s.end());
    cout << "Brute force approach : "<<endl;
    print(ans);

}



// Better approach


void better(vector<int> &vec, int n, int t){
    set<vector<int>> s;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            set<long long> hst;
            for (int k = j + 1; k < n; k++){
                long long sum = vec[i] + vec[j];
                sum += vec[k];
                long long last = t - sum;
                if (hst.find(last) != hst.end()){
                    vector<int> tmp = {vec[i], vec[j], vec[k], (int)(last)};
                    sort(tmp.begin(), tmp.end());
                    s.insert(tmp);
                }
                hst.insert(vec[k]);
            }
        }
    }
    vector<vector<int>> ans(s.begin(), s.end());
    cout << "Better approach " << endl;
    print(ans);
}


// Optimal approach 

void optimal(vector<int>vec, int n, int t){
    sort(vec.begin(), vec.end());
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++){
        if(i>0 && vec[i] == vec[i-1]){
            continue;
        }
        for (int j = i + 1; j < n;j++){
            if(j > i+1 && vec[j] == vec[j-1]){
                continue;
            }

            int l = j + 1;
            int h = n - 1;
            while(l<h){
                long long sum = vec[i];
                sum += vec[j];
                sum += vec[l];
                sum += vec[h];
                if(sum == t){
                    vector<int> tmp = {vec[i], vec[j], vec[l], vec[h]};
                    ans.push_back(tmp);
                    l++;
                    h--;
                    while (l < h && vec[l] == vec[l - 1])
                        l++;
                    while (l < h && vec[h] == vec[h + 1])
                        h--;
                }
                else if (sum < t)
                    l++;
                else
                    h--;
            }
        }
    }
    cout << "Optimal approach " << endl;
    print(ans);
}

int main(){
    int n;
    cout << "Enter the size of the array ";
    cin>>n;
    vector<int> vec(n);
    cout << "Enter " << n << " elements in to the array " << endl;
    for (int i = 0; i < n; i++){
        cin >> vec[i];
    }
    int t;
    cout << "Enter the target value ";
    cin >> t;
    brute(vec, n, t);
    better(vec, n, t);
    optimal(vec, n, t);
}