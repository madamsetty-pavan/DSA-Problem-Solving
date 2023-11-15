#include<bits/stdc++.h>
class Solution {
public:
    int minCut(string s) {
        int ans = INT_MAX;
        vector<string> temp;
        int n = s.size();
        vector<int> cuts(n, INT_MAX);
        recursion(0, s, ans, temp, n, cuts);
        return cuts[0];
    }
    
    void recursion(int index, string &s, int &ans, vector<string>&temp, int &n, vector<int>&cuts) {
        for(int i=index; i<n; i++) {
            if(isPalindrome(s, index, i)) {
                if(i<n-1 && cuts[i+1] == INT_MAX) {
                    temp.push_back(s.substr(index, i-index+1));
                    recursion(i+1, s, ans, temp, n, cuts);
                    temp.pop_back();
                }
                if(i==n-1) {
                    cuts[index] = 0;
                    return;
                } 
                // else cuts[i] = min(cuts[i], 1 + cuts[i+1]);
                cuts[index] = min(cuts[index], 1 + cuts[i+1]);
            }
        }
    }
    
    bool isPalindrome(string &s, int i, int j) {
        while(i<=j) {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};