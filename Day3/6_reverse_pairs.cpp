/*
    Count Reverse Pairs
    Problem Statement: Given an array of numbers, you need to return the count of reverse pairs. Reverse Pairs are those pairs where i<j and arr[i]>2*arr[j].


    Example 1:
    Input: N = 5, array[] = {1,3,2,3,1)
    Output: 2
    Explanation: The pairs are (3, 1) and (3, 1) as from both the pairs the condition arr[i] > 2*arr[j] is satisfied.

    Example 2:
    Input: N = 4, array[] = {3,2,1,4}
    Output: 1
    Explanation: There is only 1 pair  ( 3 , 1 ) that satisfy the condition arr[i] > 2*arr[j]


    Brute force approach : 
        Using nested loops and checking each element with all the right side elements to it and if the condition satisfy  then increment the count and return it at last

        Time complexity : O(N^2)
        Space complexity : O(1)

    Optimal approach : 
        same as like inversion count by using merge sort concept 
        Time complexity : O(N logN) + O(N) + O(N) ==> O(N logN)
        Space complexity : O(N)

*/

#include<bits/stdc++.h>
using namespace std;



int brute(vector<int>vec, int n){
    int count = 0;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if(vec[i]>2*vec[j]){
                count++;
                cout << vec[i]<< "--" << vec[j] << "--" << count<<endl;
            }
        }
    }
    return count;
}

// optimal approach  using merge sort 



int merge(vector<int>vec, int low, int mid, int high){
    int count = 0;
    int j = mid + 1;
    for (int i = low; i <= mid; i++){
        while(j<=high && vec[i]>2LL*vec[j]){
            j++;
        }
        count += (j - (mid + 1));
    }
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while(left<=mid && right <=high){
        if (vec[left] <= vec[right]) {
            temp.push_back(vec[left++]);
        }
        else{
            temp.push_back(vec[right++]);
        }
    }
    while(left<=mid){
        temp.push_back(vec[left++]);
    }
    while(right<=high){
        temp.push_back(vec[right++]);
    }

    for (int i = low; i <= high; i++){
        vec[i] = temp[i - low];
    }
    return count;
}


int ms(vector<int>vec, int low, int high){
    if(low>=high)
        return 0;
    int mid = (low + high) / 2;
    int inv = ms(vec, low, mid);
    inv += ms(vec, mid + 1, high);
    inv += merge(vec, low, mid, high);
    return inv;
}

int optimal(vector<int>vec, int n){
    return ms(vec, 0, n - 1);
} 


int main(){
    int n;
    cout << "Enter the size of the array ";
    cin >> n;
    vector<int> vec(n);
    cout << "Enter " << n << " elements in to the array " << endl;
    for (int i = 0; i < n; i++){
        cin >> vec[i];
    }

    cout << "Brute force approach " << brute(vec, n) << endl;
    cout << "Optimal approach " << optimal(vec, n) << endl;
}