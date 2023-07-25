class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>words;
        vector<int>dp(s.size(),-1);
        for(auto x:wordDict) {
            words.insert(x);
        }
        return recurse(s,words,0,dp);
    }
    
    int recurse(string s, unordered_set<string>&words, int index, vector<int>&dp) {
        if(index==s.size()) {
            return true;
        }
        if(dp[index]!=-1) return dp[index];
        string str = "";
        for(int i=index;i<s.size();i++) {
            str+=s[i];
            if(words.find(str)!=words.end()) {
                if(recurse(s,words,i+1,dp)) {
                    return dp[i] = 1;
            }
        }
        }
        return dp[index] = 0;
    }
};