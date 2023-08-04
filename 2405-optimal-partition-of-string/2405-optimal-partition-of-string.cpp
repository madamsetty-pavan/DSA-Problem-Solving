// O(n) - Time complexity
// O(1) - space complexity
class Solution {
public:
    int partitionString(string s) {
        vector<int>count(26,0);
        int ans = 1,left=0,right=0;
        while(right<s.size()) {
            if(count[s[right]-'a']!=0) 
            {
                ans++;
                while(left<right){
                    count[s[left++]-'a']--;
                }
            }
            count[s[right]-'a']++;
            right++;
        }
        return ans;
    }
};