/*
    Fractional Knapsack Problem : Greedy Approach

    Problem Statement: The weight of N items and their corresponding values are given. We have to put these items in a knapsack of weight W such that the total value obtained is maximized.

    Note: We can either take the item as a whole or break it into smaller units.

    Example:
    Input: N = 3, W = 50, values[] = {100,60,120}, weight[] = {20,10,30}.
    Output: 240.00
    Explanation: The first and second items  are taken as a whole  while only 20 units of the third item is taken. Total value = 100 + 60 + 80 = 240.00

    Approach:
        we does not cross the given weight limit and we can get the weight respective its values as a fraction also 

        so we sort the array based on the value/weight which one has more x value get takes in first and reduces its weight from the total weight 
        if total weight is less then the current element weight then we take the fraction of its  and multiply it with the remaining weight from the total weight

        Time complexity: O(n log n)+O(n)
        Space complexity: O(1)
*/


#include<bits/stdc++.h>
using namespace std;

struct item{
    int value;
    int weight;
};


bool comp(item a, item b){
    double first = (double)a.value / (double)a.weight;
    double sec = (double)b.value / (double)b.weight;
    return first > sec;
}

int solve(vector<int>values, vector<int>weights, int n, int w){
    item arr[n];
    for (int i = 0; i < n; i++){
        arr[i].value = values[i];
        arr[i].weight = weights[i];
    }
    
    sort(arr, arr + n, comp);

    int curr_weight = 0;
    double ans = 0.0;

    for (int i = 0; i < n; i++){
        if(curr_weight + arr[i].weight <=w){
            curr_weight += arr[i].weight;
            ans += arr[i].value;
        }
        else{
            int r = w - curr_weight;
            ans += (arr[i].value / (double)arr[i].weight) * (double)r;
            break;
        }
    }
    return ans;
}

int main(){
    int w;
    cout<<"Enter the total weight : ";
    cin >> w;
    int n;
    cout<<"Enter the size of the array : ";
    cin >> n;

    vector<int> values(n);
    cout<<"Enter "<<n<<" values in to the array : "<<endl;
    for (int i = 0; i < n; i++){
        cin >> values[i];
    }

    vector<int> weights(n);
    cout << "Enter " << n << " weights in to the array : " << endl;
    for (int i = 0; i < n; i++){
        cin >> weights[i];
    }

    cout << "The total value for the total weight '" << w << "' is " << solve(values, weights, n, w) << endl;
    return 0;
}