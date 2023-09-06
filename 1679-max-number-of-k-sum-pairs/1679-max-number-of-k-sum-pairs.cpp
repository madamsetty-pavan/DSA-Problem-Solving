class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int target, ans =0, n= nums.size();
        for(int i=0;i<n;i++) {
            target = k - nums[i];
            if(mp[target]>0) {
                ans++;
                mp[target]--;
            } else
            mp[nums[i]]++;
        }
        return ans;
    }
};