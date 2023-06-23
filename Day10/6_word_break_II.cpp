/*
    Word Break II
    Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.
    Note that the same word in the dictionary may be reused multiple times in the segmentation.
    
    Example 1:
    Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
    Output: ["cats and dog","cat sand dog"]
    
    Example 2:
    Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
    Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
    Explanation: Note that you are allowed to reuse a dictionary word.
    
    Example 3:
    Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
    Output: []

    Approach:
        By checking the word in the dictionary if the word is matches with the substring of string then we push the word in to the ans if not we move forward and do this recursively and return all the possible words can be formed by the  string which are in dictionary

*/


#include<bits/stdc++.h>
using namespace std;


void f(int ind, string &s, string temp, vector<string> &ans, set<string> &dict){
    if (ind == s.length()){
        temp.pop_back(); // pop the trailing space
        ans.push_back(temp);
        return;
    }

    string cur = "";
    for (int i = ind; i < s.length(); i++){
        cur.push_back(s[i]);
        if (dict.find(cur) != dict.end()){
            f(i + 1, s, temp + cur + " ", ans, dict); // adding current substring
        }
    }
}


vector<string> wordBreak(string s, vector<string> &wordDict){
    vector<string> ans;
    set<string> dict(wordDict.begin(), wordDict.end());
    f(0, s, "", ans, dict);
    return ans;
}


void print(vector<string>&ans){
    cout << "[ ";
    for(auto i:ans){
        cout << i << " ";
    }
    cout << "]";
    cout << endl;
}

int main(){
    string input;
    cout << "Enter a string : "<<endl;
    cin >> input;
    
    string dict;
    vector<string> vec;
    cout << "Enter the dictionary words  in to the vector : " << endl;
    cout << "Enter an empty string to exit the loop : " << endl;
    getline(cin, dict);
    while (true){
        getline(cin, dict);
        if (dict.empty()){
            break;
        }
        vec.push_back(dict);
    }

    vector<string> ans = wordBreak(input, vec);

    print(ans);
    return 0;
}