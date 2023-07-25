class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(),wordDict.end());
        vector<string>ans;
        int n = s.size();
        unordered_map<int,vector<string>>mp;
        recurse(s,words,ans,0,mp,n);
        return mp[0];
    }
    
    vector<string> recurse(string s, unordered_set<string>&words, vector<string>&ans, int index, unordered_map<int,vector<string>>&mp, int n ) {
        if(mp.find(index) != mp.end()) {
            return mp[index];
        }
        string str = "";
        for(int i=index;i<n;i++) {
            str += s[i];
            if (words.find(str) != words.end()) {
                if(i+1==n) {
                    mp[index].push_back(str);
                } else {
                    vector<string> value = recurse(s,words,ans,i+1,mp,n);
                for(auto x:mp[i+1]) {
                    mp[index].push_back(str+" "+x);
                }
                }
            }
        }
        return mp[index];
    }
};