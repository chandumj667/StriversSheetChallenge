/*
    Implement Pow(x,n) | X raised to the power N

    Problem Statement: Given a double x and integer n, calculate x raised to power n.
    Basically Implement pow(x, n).

    Example 1:
    Input: x = 2.00000, n = 10
    Output: 1024.00000
    Explanation: You need to calculate 2.00000 raised to 10 which gives ans 1024.00000

    Example 2:

    Input: x = 2.10000, n = 3
    Output: 9.26100
    Explanation: You need to calculate 2.10000 raised to 3 which gives ans 9.26100

    Brute force approach:
        loop from 1 to n and multiply the x with ans then return  ans
        Time complexity :O(N)
        space complexity : O(1)

    Optimal approach :
        we reduce the power factor of n to 0 by checking whether is is even or odd
        if even (n%2 ==0) we multiply the x = x*x and reduce the n by n/2
        if odd (n%2 ==1) we multiply ans with x and reduce the n by n-1;

        final check if n is given as negative value then we do reciprocal  of it as (x)^-n ==> 1/(x)^n

        Time complexity : O(logn)
        space complexity : O(1)

    Note : can the value of n be negative
*/

#include<bits/stdc++.h>
using namespace std;


double brute(double x, int n){
    double ans  =1.0;
    for (int i = 0; i < n; i++){
        ans *= x;
    }
    return ans;
}


double optimal(double x, int n){
    double ans = 1.0;
    int temp = n;
    if(temp<0)
        temp = -1 * temp;

    while(temp>0){
        if(temp%2 == 0){
            x *= x;
            temp /= 2;
        }
        else{
            ans *= x;
            temp -= 1;
        }
    }
    if(n<0){
        ans = (double)(1.0) / (double)(ans);
    }
    return ans;
}
int main(){
    double x;
    int n;
    cout << "Enter the value of x and n to x^n : ";
    cin >> x >> n;
    cout << "Brute force approach : " << brute(x, n) << endl;
    cout << "Optimal approach : " << optimal(x, n) << endl;
    return 0;
}