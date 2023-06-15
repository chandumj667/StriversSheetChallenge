/*
    Trapping Rainwater
    Problem Statement: Given an array of non-negative integers representation elevation of ground. Your task is to find the water that can be trapped after rain.

    Example 1:
    Input: height= [0,1,0,2,1,0,1,3,2,1,2,1]
    Output: 6
    Explanation: As seen from the diagram 1+1+2+1+1=6 unit of water can be trapped

    Example 2:
    Input:  [4,2,0,3,2,5]
    Output:9

    Brute force approach :
        The amount of water trapped on a specific building is calculated by the max elevation of left side and right side of the building minus current building height.

        Time complexity : O(n*n);
        Space complexity : O(1)

    Better approach :
        maintaining two array as left and right to store the max till i from right arr and max till i from left  in respective arrays

        Time complexity: O(n);
        Space complexity: O(n)

    Optimal approach:
        take two pointers one at 0 and another at n-1
        if height[l] > left-max update  left-max with height[i] as well as right too
        if not left-max - height[l] to the ans

        Time complexity : O(n)
        Space complexity : O(1)
*/

#include<bits/stdc++.h>
using namespace std;



int brute(vector<int>vec, int n){

    int total = 0;
    for (int i = 0; i < n; i++){
        int j = i;
        int lmax = 0;
        int rmax = 0;
        while(j>=0){
            lmax = max(lmax, vec[j]);
            j--;
        }

        j = i;
        while(j<n){
            rmax = max(rmax, vec[j]);
            j++;
        }

        total += min(lmax, rmax) - vec[i];
    }
    return total;
}




int better(vector<int>vec, int n){
    int left[n];
    int right[n];
    left[0] = vec[0];
    right[n - 1] = vec[n - 1];
    for (int i = 1; i<n; i++){
        left[i] = max(left[i - 1], vec[i]);
    }

    for (int i = n - 2; i >= 0; i--){
        right[i] = max(right[i + 1], vec[i]);
    }
    int total = 0;

    for (int i = 0; i < n; i++){
        total += min(left[i], right[i]) - vec[i];
    }
    return total;
}


int optimal(vector<int>vec, int n){
    int lmax = 0;
    int rmax = 0;
    int ans = 0;
    int l = 0;
    int r = n - 1;
    while(l<=r){
        if(vec[l] <= vec[r]){
            if(vec[l]>=lmax){
                lmax = vec[l];
            }
            else{
                ans += lmax - vec[l];
            }
            l++;
        }
        else{
            if(vec[r]>=rmax){
                rmax = vec[r];
            }
            else{
                ans += rmax - vec[r];
            }
            r--;
        }
    }
    return ans;
}




int main(){
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;
    vector<int> vec(n);
    cout << "Enter " << n << " elements in to the array " << endl;
    for (int i = 0; i < n; i++){
        cin >> vec[i];
    }
    cout << "The total amount of water trapped " << endl;
    cout << "Using brute force approach : " << brute(vec, n) << endl;
    cout << "Using better approach : " << better(vec, n) << endl;
    cout << "Using optmal approach : " << optimal(vec, n) << endl;
    return 0;
}