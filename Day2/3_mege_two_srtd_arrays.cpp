/*
    Merge two Sorted Arrays Without Extra Space
    Problem statement: Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.


    Example 1:
    Input:
    n = 4, arr1[] = [1 4 8 10]
    m = 5, arr2[] = [2 3 9]

    Output:
    arr1[] = [1 2 3 4]
    arr2[] = [8 9 10]

    Explanation:
    After merging the two non-decreasing arrays, we get, 1,2,3,4,8,9,10.


    Example2:
    Input:
    n = 4, arr1[] = [1 3 5 7]
    m = 5, arr2[] = [0 2 6 8 9]

    Output:
    arr1[] = [0 1 2 3]
    arr2[] = [5 6 7 8 9]

    Explanation:
    After merging the two non-decreasing arrays, we get, 0 1 2 3 5 6 7 8 9.

    Brute force approach:
        using an extra array of size n+m then tow pointers pointing  to two arrays respectively
        comparing both index values and arranging them increment them

        Time Complexity: O(m+n)
        Space Complexity : O(m+n)

    Optimal 1 approach :
        using a pointer at last of the first array and second pointer at the starting of the second array
        by comparing and swap those value
        then sort the arr1 and arr2

        Time complexity : O(min(n, m))+ O(nlogn)+O(mlogm)
        Space Complexity : O(1)

    Optimal : Gap method
        we calculate the gap by summation and average ceil of n+m
        by comparing the elements with the gap and swapping them to set in order
        until the gap becomes  1 
        then the arr1 and arr2 get merged 

        Time complexity : 
        Space complexity :

*/

#include<bits/stdc++.h>
using namespace std;


void brute(vector<int>arr1, vector<int>arr2, int n, int m){
    vector<int> vec;
    int a = 0;
    int b = 0;
    while(a<n && b<m){
        if(arr1[a]<=arr2[b]){
            vec.push_back(arr1[a]);
            a++;
        }
        else{
            vec.push_back(arr2[b]);
            b++;
        }
    }
    while(a<n){
        vec.push_back(arr1[a]);
        a++;
    }
    while(b<m){
        vec.push_back(arr2[b]);
        b++;
    }

    cout << endl<< "Brute force approach " << endl;
    for(auto i:vec){
        cout << i << " ";
    }
    cout << endl;
}


void optimal(vector<int>arr1, vector<int>arr2, int n, int m){
    int l = n - 1;
    int r = 0;
    while(l>=0 && r<m){
        if(arr1[l]>arr2[r]){
            swap(arr1[l], arr2[r]);
            l--;
            r++;
        }
        else{
            break;
        }
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    cout << "Optimal approach" << endl;
    for (int i = 0; i<n; i++){
        cout << arr1[i] << " ";
    }
    for (int i = 0; i < m; i++){
        cout << arr2[i] << " ";
    }
    cout << endl;
}


void swap_(vector<int>&arr1, vector<int>&arr2, int i, int j){
    if(arr1[i] >arr2[j]){
        swap(arr1[i], arr2[j]);
    }
}


void gap(vector<int>arr1, vector<int>arr2, int n, int m){
    int len = n+m;
    int gap = (len / 2) + (len % 2);
    while(gap>0){

        int l = 0;
        int r = l + gap;

        while(r<len){        
            if(l <n  && r>=n){
                swap_(arr1, arr2, l, r - n);
            }
            else if(l>=n){
                swap_(arr2, arr2, l - n, r - n);
            }
            else{
                swap_(arr1, arr1, l, r);
            }
            l++;
            r++;
        }
        if(gap == 1)
            break;
        gap = (gap / 2) + (gap % 2);
    }
    cout << "Gap method " << endl;
    for (int i = 0; i<n; i++){
        cout << arr1[i] << ' ';
    }
    for (int i = 0; i<m; i++){
        cout << arr2[i] << ' ';
    }
}

int main(){
    int n;
    int m;
    cout << "Enter the size of the First array ";
    cin >> n;
    cout << "Enter the size of the Second array ";
    cin >> m;
    vector<int> arr1(n);
    vector<int> arr2(m);
    cout << "Enter " << n << " elements in to the array 1 " << endl;
    for (int i = 0; i < n; i++){
        cin >> arr1[i];
    }

    cout << "Enter " << m << " elements in to the array 2 " << endl;
    for (int i = 0; i < m; i++){
        cin >> arr2[i];
    }

    brute(arr1, arr2, n, m);
    optimal(arr1, arr2, n, m);
    gap(arr1, arr2, n, m);
    return 0;
}