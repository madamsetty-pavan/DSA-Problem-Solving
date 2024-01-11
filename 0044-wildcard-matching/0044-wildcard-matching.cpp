// Top Down 
// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         return recurse(s,p,s.size()-1,p.size()-1);
//     }
    
//     bool recurse(string &s, string &p, int i, int j) {
//         // cout<<"intial "<<i<<" "<<j<<endl;
//         if(i<0) {
//            // cout<<j<<" "<<p[j]<<endl;
//             if(j<0) return true;
//             while(j>=0 && p[j]=='*') j--;
//             return j<0;
//             // cout<<"came"<<endl;
//         }
//         if(j<0) {
//             // cout<<"came"<<endl;
//             return false;
//         }
//         if(s[i]==p[j]) {
//             // cout<<"came at 20"<<endl;
//             return recurse(s,p,i-1,j-1);
//         }
//         else if(p[j]=='?') {
//             // cout<<"came at 24"<<endl;
//             return recurse(s,p,i-1,j-1);
//         }
//         else if(p[j] == '*') {
//             // cout<<"came at 28"<<endl;
//             // cout<<j<<" "<<p[j]<<endl;
//             return (
//                 // No match for *
//                 recurse(s,p,i,j-1) ||
//                 // Match for 1
//                 recurse(s,p,i-1,j-1) ||
//                 // More match
//                 recurse(s,p,i-1,j)
//             );
//         }
//          return false;
//     }
    
// };


// TOP Down - DP
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return recurse(s,p,s.size()-1,p.size()-1, dp);
    }
    
    bool recurse(string &s, string &p, int i, int j, vector<vector<int>> &dp) {
        if(i<0) {
            if(j<0) return true;
            while(j>=0 && p[j]=='*') j--;
            return j<0;
        }
        if(j<0) {
            return false;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j]) {
            return dp[i][j]=recurse(s,p,i-1,j-1,dp);
        }
        else if(p[j]=='?') {
            return dp[i][j]=recurse(s,p,i-1,j-1,dp);
        }
        else if(p[j] == '*') {
            return dp[i][j]=(
                // No match for *
                recurse(s,p,i,j-1,dp) ||
                // Match for 1
                recurse(s,p,i-1,j-1,dp) ||
                // More match
                recurse(s,p,i-1,j,dp)
            );
        }
         return false;
    }
    
};