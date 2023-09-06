class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++) {
            mp[nums[i]]++;
        }
        int ans = 0, target;
        for(int i=0;i<nums.size();i++) {
            if(mp[nums[i]]==0) continue;
            target = k - nums[i];
            if(mp.find(target) != mp.end() && mp[target]>0) {
                if (target == nums[i]) {
                    if(mp[target]>1) {
                        ans++;
                        mp[target] -= 2;
                    }
                } else {
                    ans++;
                    mp[target]--;
                    mp[nums[i]]--;
                }
            }
        }
        return ans;
    }
};