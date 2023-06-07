/*
    Count inversions in an array
    Problem Statement: Given an array of N integers, count the inversion of the array (using merge-sort).
    What is an inversion of an array? Definition: for all i & j < size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].

    Example 1:
    Input Format: N = 5, array[] = {1,2,3,4,5}
    Result: 0
    Explanation: we have a sorted array and the sorted array
    has 0 inversions as for i < j you will never find a pair
    such that A[j] < A[i]. More clear example: 2 has index 1
    and 5 has index 4 now 1 < 5 but 2 < 5 so this is not an
    inversion.

    Example 2:
    Input Format: N = 5, array[] = {5,4,3,2,1}
    Result: 10
    Explanation: we have a reverse sorted array and we will
    get the maximum inversions as for i < j we will always
    find a pair such that A[j] < A[i].
    Example: 5 has index 0 and 3 has index 2 now (5,3) pair
    is inversion as 0 < 2 and 5 > 3 which will satisfy out
    conditions and for reverse sorted array we will get
    maximum inversions and that is (n)*(n-1) / 2.
    For above given array there is 4 + 3 + 2 + 1 = 10 inversions.
    
    Example 3:
    Input Format: N = 5, array[] = {5,3,2,1,4}
    Result: 7
    Explanation: There are 7 pairs (5,1), (5,3), (5,2), (5,4),
    (3,2), (3,1), (2,1) and we have left 2 pairs (2,4) and
    (1,4) as both are not satisfy our condition.


    brute force approach :
        using nested loops checking for each element with other elements right of it and if they satisfy the condition then increment the count

        Time complexity : O(N^2)
        Space complexity : O(1)

    Optimal approach :

*/



#include<bits/stdc++.h>
using namespace std;

// brute force approach 
int brute(vector<int>vec, int n){
    int count = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(vec[i]>vec[j]){
                count++;
            }
        }
    }
    return count;
}


// Optimal

int merge(vector<int>&arr, vector<int>&temp, int left, int mid, int right)
{
    int count = 0;

    int i = left;
    int j = mid;
    int k = left;
    while ((i <= mid - 1) && (j <= right))
    {

        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {

            temp[k++] = arr[j++];
            count = count + (mid - i);
        }
    }
    while (i <= mid - 1)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return count;
}

int merge_sort(vector<int>&arr, vector<int>&temp, int l, int r)
{

    int mid;
    int  count = 0;
    if (r > l)
    {
        mid = (l+r)/2;
        count += merge_sort(arr, temp, l, mid);
        count += merge_sort(arr, temp, mid + 1, r);
        count += merge(arr, temp, l, mid + 1, r);
    }

    return count;
}

int optimal(vector<int>vec, int n) {
    // Write your code here.
    vector<int>temp;
    int count = merge_sort(vec, temp, 0, n - 1);
    return count;
}

int main()
{
    int n;
    cout << "Enter the size of the array ";
    cin >> n;
    vector<int>vec(n);
    cout << "Enter " << n << " elements in to the array " << endl;
    for (int i = 0; i < n; i++){
        cin >> vec[i];
    }
    cout << "Brute force approach : " << brute(vec, n) <<endl;

    cout << "Optimal approach : ";
    cout<<optimal(vec, n) << endl;
    return 0;
}