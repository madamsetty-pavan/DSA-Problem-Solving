class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> tempAns;
        recurse(0, s, tempAns, ans);
        return ans;
    }
    
    void recurse(int index, string &s, vector<string>&tempAns,vector<vector<string>> &ans) {
        if(index == s.size()) {
            ans.push_back(tempAns);
            return;
        }
        string str = "";
        for(int i=index;i<s.size();i++) {
            str += s[i];
            if(isPalindrome(str)) {
                tempAns.push_back(str);
                recurse(i+1, s, tempAns, ans);
                tempAns.pop_back();
            }
        }
    }
    
    bool isPalindrome(string &str) {
        for(int i=0, j= str.size()-1; i<j;i++,j--) {
            if(str[i]!=str[j]) return false;
        }
        return true;
    }
};