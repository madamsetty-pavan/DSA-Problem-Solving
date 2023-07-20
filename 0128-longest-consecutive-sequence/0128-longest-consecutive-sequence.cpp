class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> mp;
        for(auto x:nums)
        {
            mp[x]=1;
        }
        int ans=0;
        for(auto x=mp.begin();x!=mp.end();x++)
        {
          x->second=mp[(x->first)-1]+1;
            ans=max(ans,x->second);
        }
        return ans;
    }
};