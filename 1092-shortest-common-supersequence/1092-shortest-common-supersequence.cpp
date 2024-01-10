class Solution {
public:
    string shortestCommonSupersequence(string &str1, string &str2) {
        int n = str1.size(), m = str2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(str1[i-1] == str2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        vector<int> indexes1, indexes2;
        int i = n, j = m;
        while(indexes1.size()<dp[n][m]) {
            if(str1[i-1] == str2[j-1]) {
                indexes1.push_back(i-1);
                indexes2.push_back(j-1);
                i--;
                j--;
            } else {
                if(dp[i-1][j] >= dp[i][j-1]) i--;
                else j--;
            }
        }
        string ans = "";
        i = n-1, j = m-1;
        for(int count=0;count<indexes1.size();count++) {
            while(i>indexes1[count]) {
                ans += str1[i--];
            }
            while(j>indexes2[count]) {
                ans += str2[j--];
            }
            ans+=str1[i--];
            j--;
        }
        while(i>=0) ans += str1[i--];
        while(j>=0) ans += str2[j--];
        reverse(ans.begin(), ans.end());
        return ans;
    }
};