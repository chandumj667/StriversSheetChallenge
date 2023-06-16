/*
    Minimum number of platforms required for a railway
    Problem Statement: We are given two arrays that represent the arrival and departure times of trains that stop at the platform. We need to find the minimum number of platforms needed at the railway station so that no train has to wait.

    Examples 1:
    Input: N=6,
    arr[] = {9:00, 9:45, 9:55, 11:00, 15:00, 18:00}
    dep[] = {9:20, 12:00, 11:30, 11:50, 19:00, 20:00}
    Output:3
    Explanation: There are at-most three trains at a time. The train at 11:00 arrived but the trains which had arrived at 9:45 and 9:55 have still not departed. So, we need at least three platforms here.


    Example 2:
    Input Format: N=2,
    arr[]={10:20,12:00}
    dep[]={10:50,12:30}
    Output: 1


    Approach:
        we sort both the arrays and using two pointer approach
        we traverse the two arrays from starting  i=0, j=0;
        if(arr[i] <= dept[j]) plt++; i++;
        else if(arr[i]>dept[j]) plt--; j++;
        result = max(result, plt);

        Time complexity: O(n log n)
        Space complexity: O(1)

*/


#include<bits/stdc++.h>
using namespace std;


int solve(vector<int>arr, vector<int>dept, int n){
    sort(arr.begin(), arr.end());
    sort(dept.begin(), dept.end());

    int i = 0;
    int j = 0;
    int plt = 0;
    int maxi = 0;
    while(i<n && j<n){
        if(arr[i]<=dept[j]){
            plt++;
            i++;
        }
        else if(arr[i]>dept[j]){
            plt--;
            j++;
        }
        maxi = max(maxi, plt);
    }
    return maxi;
}

int main(){
    int n;
    cout << "Enter the size of the arrays : ";
    cin >> n;
    vector<int> arrival(n);
    vector<int> dept(n);
    cout << "Enter " << n << " arrival times in to the arrival array :" << endl;
    for (int i = 0; i < n; i++){
        cin >> arrival[i];
    }
    cout << "Enter " << n << " departure times in to the departure array :" << endl;
    for (int i = 0; i < n; i++){
        cin >> dept[i];
    }
    cout << "The maximum number of platforms required : " << solve(arrival, dept, n);
    return 0;

}