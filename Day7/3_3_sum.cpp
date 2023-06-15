/*
    3 Sum : Find triplets that add up to a zero
    Problem Statement: Given an array of N integers, your task is to find unique triplets that add up to give a sum of zero. In short, you need to return an array of all the unique triplets [arr[a], arr[b], arr[c]] such that i!=j, j!=k, k!=i, and their sum is equal to zero.

    Example 1:
    Input: nums = [-1,0,1,2,-1,-4]
    Output: [[-1,-1,2],[-1,0,1]]
    Explanation: Out of all possible unique triplets possible, [-1,-1,2] and [-1,0,1] satisfy the condition of summing up to zero with i!=j!=k

    Example 2:
    Input: nums=[-1,0,1,0]
    Output: Output: [[-1,0,1],[-1,1,0]]
    Explanation: Out of all possible unique triplets possible, [-1,0,1] and [-1,1,0] satisfy the condition of summing up to zero with i!=j!=l


    Brute force approach:
        using nested loops i => 0 to n, j => i+1 to n, l => j+1 to n ;

        Time complexity: O(n^3)
        Space complexity : O(3*k)

    Better approach:
        sort the array
        then fix the i pointer as i from 0 to n and j and l pointers as j = i+1 and l= n-1;

        then do the two pointer approach and if the j and l loop terminates increment the i;

        Time complexity: O(n^2)
        Space complexity: O(3*k)
*/

#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>>ans){
    for(auto i: ans){
        for(auto c:i){
            cout << c << " ";
        }
        cout << endl;
    }
}


void brute(vector<int>vec, int n, int k){
    vector<vector<int>> ans;
    vector<int> inn;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            for (int l = j + 1; l < n;l++){
                inn.clear();
                if(vec[i]+vec[j]+vec[l] == k){
                    inn.push_back(vec[i]);
                    inn.push_back(vec[j]);
                    inn.push_back(vec[l]);
                }
                if(inn.size()!=0){
                    ans.push_back(inn);
                }
            }

        }
    }
    cout << endl<< "using  brute force approach " << endl;
    print(ans);
    cout << endl;
}



void optimal(vector<int>vec, int n, int k){
    vector<vector<int>> ans;
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n-2; i++){
        if(i==0 || (i>0 && vec[i]!=vec[i-1])){
            int low = i + 1;
            int high = n - 1;
            int sum = k-vec[i];
            while(low<high){
                if(vec[low] +vec[high] == sum){
                    vector<int> inn;
                    inn.push_back(vec[i]);
                    inn.push_back(vec[low]);
                    inn.push_back(vec[high]);
                    ans.push_back(inn);

                    while(low<high &&vec[low] == vec[low+1])
                        low++;
                    while(low<high &&vec[high] ==  vec[high-1])
                        high--;
                }
                else if(vec[low]+vec[high]<sum){
                    low++;
                }
                else{
                    high--;
                }
            }
        }
    }
    cout << "Using optimal approach : " << endl;
    print(ans);
    
}

int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    vector<int> vec(n);
    cout << "Enter "<<n<<" the elements in to the array " << endl;
    for (int i = 0; i < n; i++){
        cin >> vec[i];
    }
    int k;
    cout << "Enter the target sum : ";
    cin >> k;
    brute(vec, n, k);
    optimal(vec, n, k);
    return 0;
}