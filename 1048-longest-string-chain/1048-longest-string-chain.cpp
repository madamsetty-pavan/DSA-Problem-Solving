class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size(),ans = 1;
        vector<int> dp(n,1);
        sort(words.begin(), words.end(), compare);
        for(int i=0;i<n;i++) {
            for(int prev=0;prev<i;prev++) {
                if(checkIfIS(words[prev], words[i])) {
                    if(dp[i] < 1 + dp[prev]) {
                        dp[i] = 1 + dp[prev];
                    }
                } 
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
    
    bool static compare(string &s1, string &s2) {
        return s1.size()<s2.size();
    }
    
    bool checkIfIS(string &s1, string &s2) {
        int i = 0, j = 0, n = s1.size(), m = s2.size(), flag = 0;
        if(m-n != 1) return false;
        while(i<n && j<m) {
            if(s1[i] != s2[j]) {
                if(flag == 1) return false;
                flag = 1;
                j++;
                continue;
            }
            i++;
            j++;
        }
        return (j>=m-1);
    }
};