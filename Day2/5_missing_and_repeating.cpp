/*
    Find the repeating and missing numbers
    Problem Statement: You are given a read-only array of N integers with values also in the range [1, N] both inclusive. Each integer appears exactly once except A which appears twice and B which is missing. The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.

    Example 1:
    Input Format:  array[] = {3,1,2,5,3}
    Result: {3,4)
    Explanation: A = 3 , B = 4
    Since 3 is appearing twice and 4 is missing
    
    Example 2:
    Input Format: array[] = {3,1,2,5,4,6,7,5}
    Result: {5,8)
    Explanation: A = 5 , B = 8
    Since 5 is appearing twice and 8 is missing

    Brute force approach :
        given that the numbers between 1 to n
        traverse the array check each element with other if it appears the same then it is the repeating number
        then check all the elements with numbers between 1 to n if there is any missing return it as missing number

        Time complexity : O(N^2)
        Space complexity : O(1)

    Better approach: 
        Use hashmap or hash-array[n] ={0}
        by increment +1 for the elements in the array in hash-array and traverse the hash-array if ith value ==2 then it is duplicate if ith value is 0 then it is the missing number

        Time complexity : O(N)
        Space complexity :O(1)

    optimal 1: 
        using math sum all the elements in the array and mark it as s1
        sum all the natural numbers from 1 ot n mark the sum as s2

        sum up all the squares of elements in the array and mark it as t1
        sum up all the squares of elements from 1 to n and mark it as t2

        s1-s2 = k -->1
        t1-t2 = l ===>  t1 ==> s1^2 and t2 ==> s2^2
                        s1^2 - s2^2 ==> (a^2 - b^2) =(a+b)(a-b) as we already have s1-s2 and substitute the value here
                        (s1+s2)(s1-s2) = l
                        (s1+s2)(k) = l
                        s1+s2 = l/k -->2
        s1-s2 = k
        s1+s2 = l/k
        2s1 = k+l/k
        s1 =( k+l/k)/2 --> rep 

        s1-s2 = k
        rep -s2 = k
        rep -k = s2 -->mis

        we get rep and miss

        Time complexity :O(N)
        Space complexity: o(1)


*/

#include<bits/stdc++.h>
using namespace std;

void print(pair<int, int>vec){
    cout << "Duplicate number is [" << vec.first << "] and Missing number is [" << vec.second<<"]"<<endl;
}


void brute(vector<int>vec, int n){
    pair<int, int> ans;
    int a = -1;
    int b = -1;
    for (int i = 1; i <=n; i++){
        int count = 0;
        for (int j = 0; j < n; j++){
            if(vec[j] == i){
                count++;
            }
        }
        if(count == 2){
            a = i;
        }else if(count == 0){
            b = i;
        }
    }
    cout << endl;
    cout << "Brute force approach" << endl;
    print({a, b});
}


void better(vector<int>vec, int n){
    int hash[n] = {0};
    for (int i = 0; i < n; i++){
        hash[vec[i]]++;
    }
    int a = -1;
    int b = -1;
    for (int i = 1; i <= n; i++){
        if(hash[i] ==2){
            a = i;
        }
        else if(hash[i] ==0){
            b == i;
        }
    }
    cout << "Better approach " << endl;
    print({a, b});
}


void optimal(vector<int>vec, int siz){
    long long s1 = 0;
    long long t1 = 0;
    for (auto i:vec){
        s1 += i;
        t1 += (long long)i * (long long)i;
    }
    long long n = (long long)siz;
    long long s2 = (n * (n + 1)) / 2;
    long long t2 = ((n) * (n + 1) * (2 * n + 1)) / 6;


    long long val1 = s1-s2;
    long long val2 = t1 - t2;
    val2 = val2 / val1;
    long long a = (val1 + val2) / 2;
    long long b = a - val1;
    cout << "Optimal approach" << endl;
    print({(int)a,(int)b});
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
    brute(vec, n);
}