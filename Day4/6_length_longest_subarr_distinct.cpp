/*
    Length of Longest Substring without any Repeating Character
    Problem Statement: Given a String, find the length of longest substring without any repeating character.

    Example 1:
    Input: s = ”abcabcbb”
    Output: 3
    Explanation: The answer is abc with length of 3.

    Example 2:
    Input: s = ”bbbbb”
    Output: 1
    Explanation: The answer is b with length of 1 units.

    Brute force approach :

        use loops nested inside each to generate all the substrings 
        time complexity : O(n^3)
        slightly change that the inner loops does not require and iit reduces the time complexity.

        nested loops for checking the window whether the window consists of duplicates or not 
        Time complexity : O(n^2)

    Better approach :

*/


#include<bits/stdc++.h>
using namespace std;


int brute(string s){
    if(s.size() == 0)
        return 0;
    int ans = INT_MIN;
    for (int i = 0; i < s.length(); i++){
        unordered_set<int> st;
        for (int j = i; j < s.length(); j++){
            if(st.find(s[j]) != st.end()){
                ans = max(ans, j - i);
                break;
            }
            st.insert(s[j]);
        }
    }
    return ans;
}


int better(string s){
    if(s.size() == 0){
        return 0;
    }
    int ans = INT_MIN;
    unordered_set<int> st;
    int l = 0;
    for (int r = 0; r < s.length(); r++){
        if(st.find(s[r]) != st.end()){
            while(l<r && st.find(s[r])!=st.end()){
                st.erase(s[l]);
                l++;
            }
        }
        st.insert(s[r]);
        ans = max(ans, r - l + 1);
    }
    return ans;
}


int optimal(string s){
    vector<int> mp(256, -1);
    int l = 0;
    int r = 0;
    int ans = 0;
    while(r<s.size()){
        if(mp[s[r]] != -1){
            l = max(mp[s[r]] + 1, l);
        }
        mp[s[r]] = r;
        ans = max(ans, r - l + 1);
        r++;
    }
    return ans;
}

int main(){
    string s;
    cout << "Enter the string : " << endl;
    getline(cin, s);
    cout << "Brute force approach : " << brute(s) << endl;
    cout << "Better approach : " << better(s)<<endl;
    cout << "Optimal approach : " << optimal(s);
    return 0;
}

