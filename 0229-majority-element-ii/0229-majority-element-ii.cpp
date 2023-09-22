class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int cnt1 = 0, cnt2 = 0, el1, el2, n=nums.size();
        for(int i=0; i<n; i++) {
            if(cnt1==0 && nums[i]!=el2) {
                cnt1 = 1;
                el1 = nums[i];
            } else if(cnt2==0 && nums[i]!=el1) {
                cnt2 = 1;
                el2 = nums[i];
            } else if(nums[i] == el1) cnt1++;
            else if(nums[i] == el2) cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0, cnt2 = 0;
        for(int i=0;i<n;i++) {
            if(nums[i] == el1) cnt1++;
            if(nums[i] == el2) cnt2++;
        }
        if(cnt1>floor(n/3)) ans.push_back(el1);
        if(cnt2>floor(n/3)) ans.push_back(el2);
        return ans;
    }
};