/*
    Nth Root of a Number using Binary Search
    Problem Statement: Given two numbers N and M, find the Nth root of M.
    The nth root of a number M is defined as a number X when raised to the power N equals M.

    Example 1:
    Input: N=3 M=27
    Output: 3
    Explanation: The cube root of 27 is 3.

    Example 2:
    Input: N=2 M=16
    Output: 4
    Explanation: The square root of 16 is 4

    Example 3:
    Input: N=5 M=243
    Output: 3
    Explanation: The 5th root of 243 is 3

    Approach:
        By using binary search we solve this problem
        the intuition behind the logic is
        We take the range from 1 to n and if the multiplication of middle of 1 and n gives more than n then make the high as mid if  multiplication of mid with m times is less than high then make the low as mid 
        return the value in double 

        Time complexity:
        Space complexity: 
*/

#include<bits/stdc++.h>
using namespace std;

double multi(double mid, int n){
    double ans = 1.0;
    for (int i = 1; i <= n; i++){
        ans = ans * i;
    }

    return ans;
}


double solve(int n, int m){
    double low = 1;
    double high = m;
    double epsilon = 1e-6;
    while((high-low)>epsilon){
        double mid = (low + high) / 2.0;
        if(multi(mid, n)<m){
            low = mid;
        }
        else{
            high = mid;
        }
    }
    return pow(m, (double)(1.0 / (double)n));
}

int main(){
    int n;
    int m;
    cout << "Enter the number n and m : " << endl;
    cin >> n;
    cin >> m;

    cout<<n<<" root "<<m<<" value is "<< solve(n, m);
}