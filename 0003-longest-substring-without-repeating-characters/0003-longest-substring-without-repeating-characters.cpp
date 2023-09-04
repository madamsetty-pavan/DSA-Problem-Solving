class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> dict; 
        int left = 0, right = 0 , ans = 0;
        while(right<s.size()) {
            while(dict.find(s[right]) != dict.end()) {
                dict.erase(s[left++]);
            }
            ans = max(ans, right-left+1);
            dict.insert(s[right++]); 
        }
        return ans;
    }
};