class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0, ele1 = 10e5, ele2 = 10e5, n = nums.size();
        for(int i=0;i<n;i++) {
            if (cnt1==0 && nums[i]!=ele2) {
                cnt1++;
                ele1 = nums[i];
            } else if(cnt2==0 && nums[i]!=ele1) {
                cnt2++;
                ele2 = nums[i];
            } else if(nums[i] == ele1) {
                cnt1++;
            } else if(nums[i] == ele2) {
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0, cnt2 = 0;
        for (int i = 0;i<n;i++) {
            if(ele1 == nums[i]) cnt1++;
            if(ele2 == nums[i]) cnt2++;
        }
        vector<int> ans;
        if(cnt1 > floor(n/3)) ans.push_back(ele1);
        if(cnt2 > floor(n/3)) ans.push_back(ele2);
        return ans;
    }
};