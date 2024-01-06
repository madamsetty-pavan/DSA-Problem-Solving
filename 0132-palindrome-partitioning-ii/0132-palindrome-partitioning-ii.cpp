// Top - Down Approach
// class Solution {
// public:
//     int minCut(string s) {
//         int n = s.size();
//         vector<int> dp(n,-1);
//         return recurse(0, s, dp,n);
//     }

//     int recurse(int index, string &s, vector<int> &dp, int &n) {
//         if(index >= n) return -1;
//         if(dp[index] != -1) return dp[index];
//         string str = "";
//         int ans = INT_MAX;
//         for(int i = index;i<n;i++) {
//             str += s[i];
//             if(isPalindrome(str)) {
//                 ans = min(ans, 1 + recurse(i+1, s, dp, n));
//             }
//         }
//         return dp[index] = ans;
//     }
    
//     bool isPalindrome(string &str) {
//         for(int i = 0, j = str.size()-1; i<j; i++,j--) {
//             if(str[i] != str[j]) return false;
//         }
//         return true;
//     }
// };



// Bottom up Approach
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n,0);
        for(int i=n-2; i>=0; i--) {
            int ans = INT_MAX;
            string str = "";
            for(int j=i;j<n;j++) {
                str += s[j];
                if(isPalindrome(str)) {
                    if(j+1<n) 
                        ans = min(ans, 1 + dp[j+1]);
                    else ans = min(ans, 0);
                }
            }
            dp[i]  = ans;
        }
        return dp[0];
    }
    
    bool isPalindrome(string &str) {
        for(int i = 0, j = str.size()-1; i<j; i++,j--) {
            if(str[i] != str[j]) return false;
        }
        return true;
    }
};