/*
    Find K-th Permutation Sequence
    Problem Statement: Given N and K, where N is the sequence of numbers from 1 to N([1,2,3….. N]) find the Kth permutation sequence.
    For N = 3  the 3!  Permutation sequences in order would look like this:-
    Note: 1<=K<=N! Hence for a given input its Kth permutation always exists

    Example 1:
    Input: N = 3, K = 3
    Output: “213”
    Explanation: The sequence has 3! permutations as illustrated in the figure above. K = 3 corresponds to the third sequence.

    Example 2:
    Input: N = 3, K = 5
    Result: “312”
    Explanation: The sequence has 3! permutations as illustrated in the figure above. K = 5 corresponds to the fifth sequence.

    Brute force approach:
        Using recursion by generating all the permutations and finding the k-th permutation out of all the generated permutations.

        Time complexity: O(N! * N) +O(N! Log N!)
        Space complexity: O(N)


    Optimal approach: 


*/


#include<bits/stdc++.h>
using namespace std;


void result(string &s, int ind, vector<string>&vec){
    if(ind == s.size()){
        vec.push_back(s);
        return;
    }
    for (int i = ind; i < s.size(); i++){
        swap(s[i], s[ind]);
        result(s, ind + 1, vec);
        swap( s[i], s[ind] );
    }
}

string solve(int n, int k){
    string s;
    vector<string> vec;
    for (int i = 1; i <= n; i++){
        s.push_back(i + '0');
    }
    result(s, 0, vec);
    sort(vec.begin(), vec.end());
    auto i = vec.begin() + (k - 1);
    return *i;
}


void print(string ans, int k){
    cout << "The " << k << " th permutation is : " << ans << endl;
}


string optimal(int n, int k){
    int fact = 1;
    vector<int> vec;
    for (int i = 1; i < n; i++){
        fact = fact * i;
        vec.push_back(i);
    }
    vec.push_back(n);

    string ans = "";
    k = k - 1;
    while(true){
        ans = ans + to_string(vec[k / fact]);
        vec.erase(vec.begin() + k / fact);
        if(vec.size() == 0){
            break;
        }
        k = k % fact;
        fact = fact / vec.size();
    }
    return ans;
}


int main(){
    int n;
    cout << "Enter the number 'n': ";
    cin >> n;
    int k;
    cout << "Enter the number 'k': ";
    cin >> k;

    string ans = solve(n, k);
    cout << "Brute force approach: " << endl;
    print(ans, k);
    
    string ans2 = optimal(n, k);
    cout << "Using optimal approach: " << endl;
    print(ans2, k);
}