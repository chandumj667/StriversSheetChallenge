/*
    Majority Elements(>N/3 times) | Find the elements that appears more than N/3 times in the array
    Problem Statement: Given an array of N integers. Find the elements that appear more than N/3 times in the array. If no such element exists, return an empty vector.

    Pre-requisite: Majority Element(>N/2 times)

    Example 1:
    Input Format: N = 5, array[] = {1,2,2,3,2}
    Result: 2
    Explanation: Here we can see that the Count(1) = 1, Count(2) = 3 and Count(3) = 1.Therefore, the count of 2 is greater than N/3 times. Hence, 2 is the answer.

    Example 2:
    Input Format:  N = 6, array[] = {11,33,33,11,33,11}
    Result: 11 33
    Explanation: Here we can see that the Count(11) = 3 and Count(33) = 3. Therefore, the count of both 11 and 33 is greater than N/3 times. Hence, 11 and 33 is the answer.

    Brute force:
        make teh count of each value using nested loops and use the list to add the elements which appeared more than n/3 times

        Time complexity : O(N^2)
        Space complexity : O(1)

    Better approach:
        use hashmap or hash array to maintain frequency of each value
        if i.second > n/3 then append i.first to the list

        Time complexity : O(N)
        Space complexity : O(N)

    Optimal approach:
        same as like the n/2 problem maintaining two element variables this time
        if(cnt1 == 0 and ele2 != nums[i])then assign it to the ele1 same for ele2
        if both cnt not equal to o then check it with the ele1 and ele2 if any match increment respective count if not matche for both decrease the both count.

        Time complexity : O(N)
        Space complexity : O(1)


*/

#include <bits/stdc++.h>
using namespace std;

void better(vector<int> vec, int n)
{
    unordered_map<int, int> ump;
    for (int i = 0; i < n; i++)
    {
        ump[vec[i]]++;
    }
    for (auto i : ump)
    {
        if (i.second > n / 3)
        {
            cout << i.first << " ";
        }
    }
}

void optimal(vector<int>vec, int n)
{
    vector<int> lis;
    int ele1 = INT_MIN;
    int ele2 = INT_MIN;
    int cnt1 = 0;
    int cnt2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (cnt1 == 0 && vec[i] != ele2)
        {
            cnt1 = 1;
            ele1 = vec[i];
        }
        else if (cnt2 == 0 && vec[i] != ele1)
        {
            cnt2 = 1;
            ele2 = vec[i];
        }
        else if (vec[i] == ele1)
        {
            cnt1++;
        }
        else if (vec[i] == ele2)
        {
            cnt2++;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = 0;
    cnt2 = 0;
    for (int i = 0; i < n; i++){
        if(vec[i] == ele1){
            cnt1++;
        }
        if(ele2 == vec[i]){
            cnt2++;
        }
    }
        if (cnt1 >= (int)(n / 3) + 1)
        {
            lis.push_back(ele1);
        }
    if (cnt2 >= (int)(n / 3)+1)
    {
        lis.push_back(ele2);
    }

    for (auto i : lis)
    {
        cout << i << " ";
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;
    vector<int> vec(n);
    cout << "Enter " << n << " elements in to the array " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    cout << "Better approach  : ";
    better(vec, n);
    cout << endl;
    cout << "Optimal approach  : ";
    optimal(vec, n);
    cout << endl;
    return 0;
}