/*
    N meetings in one room
    Problem Statement: There is one meeting room in a firm. You are given two arrays, start and end each of size N.For an index ‘i’, start[i] denotes the starting time of the ith meeting while end[i]  will denote the ending time of the ith meeting. Find the maximum number of meetings that can be accommodated if only one meeting can happen in the room at a  particular time. Print the order in which these meetings will be performed.

    Example:
    Input:  N = 6,  start[] = {1,3,0,5,8,5}, end[] =  {2,4,5,7,9,9}
    Output: 1 2 4 5

    Approach :
        we sort the meets according to their end times if they are equal then sort them according their position/index
        then create a vector with a struct type of int start, int end, int pos in it
        int limit  = meet[0].end
        then compare the limit with next occurring index start time if it greater than the limit then push_back its position and make limit as its end


        Time complexity: O(n) + O(n log n)+ O(n)
                        O(n)
        Space complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

struct meets{
    int start;
    int end;
    int pos;
};

bool comp(meets m1, meets m2){
    if (m1.end < m2.end)
        return true;
    else if (m1.end > m2.end)
        return false;
    else if (m1.pos < m2.pos)
        return true;
    else
        return false;
};

void solve(vector<int> &st, vector<int> &en, int n){
    meets meet[n];
    for (int i = 0; i < n; i++){
        meet[i].start = st[i];
        meet[i].end = en[i];
        meet[i].pos = i + 1;
    }
    sort(meet, meet + n, comp);

    vector<int> vec;
    int limit = meet[0].end;
    vec.push_back(meet[0].pos);
    for (int i = 1; i < n; i++){
        if (meet[i].start > limit){
            limit = meet[i].end;
            vec.push_back(meet[i].pos);
        }
    }
    for (int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
}

int main(){
    int n;
    cout << "Enter the size of the arrays : ";
    cin >> n;
    vector<int> st(n);
    vector<int> en(n);
    cout << "Enter " << n << " elements in to the starting array : " << endl;
    for (int i = 0; i < n; i++){
        cin >> st[i];
    }
    cout << "Enter " << n << " elements in to the ending array : " << endl;
    for (int i = 0; i < n; i++){
        cin >> en[i];
    }
    solve(st, en, n);
}
