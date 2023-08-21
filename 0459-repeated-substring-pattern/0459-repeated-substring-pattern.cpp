class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string ans = "";
        for(int i=0;i<s.size()-1;i++) {
            ans += s[i];
            if(isRepeated(ans, s)) {
                return true;
            }
        }
        return false;
    }
    bool isRepeated(string &ans, string &s) {
        string x ="";
        while(x.size()<s.size()) {
            x += ans;
        }
        return (x==s);
    }
};