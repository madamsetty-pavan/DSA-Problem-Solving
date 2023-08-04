class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> str({"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"});
        vector<string> ans;
        recurse(ans,str,digits,0,"");
        return ans;
    }
    
    void recurse(vector<string> &ans, vector<string>&str,string digits, int index, string temp) {
        if(temp.size()==digits.size()) {
            if(temp.size()) ans.push_back(temp);
            return;
        }
        int presentIndex = digits[index]-'0'-2;
        for(int i=0;i<str[presentIndex].size();i++) {
            recurse(ans,str,digits,index+1,temp+str[presentIndex][i]);
        }
    }
};