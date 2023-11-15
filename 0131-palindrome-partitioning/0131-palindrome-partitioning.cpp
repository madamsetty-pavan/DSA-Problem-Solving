class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        int n = s.size();
        recursion(0, s, ans, temp, n);
        return ans;
    }
    
    void recursion(int index, string &s , vector<vector<string>>&ans, vector<string>&temp, int &n) {
        if(index==n) {
            ans.push_back(temp);
            return;
        }
        string str = "";
        for(int i=index;i<n;i++) {
            str+=s[i];
            if(isPalindrome(str)) {
                temp.push_back(str);
                recursion(i+1, s, ans, temp, n);
                temp.pop_back();
            }
        }
    }
    
    bool isPalindrome(string &s) {
        int i = 0, j = s.size()-1;
        while(i<=j) {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};