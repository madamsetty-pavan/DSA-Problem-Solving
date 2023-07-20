class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string>temp;
        recurse(ans,temp,s,0);
        return ans;
    }
    
    void recurse(vector<vector<string>>&ans, vector<string>&temp, string s, int index) {
        if(index==s.size()) {
            ans.push_back(temp);
            return;
        }
        string str = "";
        for(int i=index;i<s.size();i++) {
            str += s[i];
            if(isPalindrome(str)){
                temp.push_back(str);
                recurse(ans,temp,s,i+1);
                temp.pop_back();
            }
        }
    }
    
    bool isPalindrome(string str) {
        int first = 0, end= str.size()-1;
        while(first<=end) {
            if(str[first]!=str[end]) return false;
            first++;
            end--;
        }
        return true;
    }
};