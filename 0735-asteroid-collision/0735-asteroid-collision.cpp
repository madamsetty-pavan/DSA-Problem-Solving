class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        vector<int> ans;
        bool pushFlag = 1;
        for(int i=0;i<nums.size();i++) {
           if(ans.size() && ans.back()>0 && nums[i]<0) {
               pushFlag = 1;
               while(ans.size() && ans.back()>0 && nums[i]<0) {
                   if(abs(ans.back()) < abs(nums[i])) {ans.pop_back();}
                   else if(abs(ans.back()) == abs(nums[i])) {
                       ans.pop_back();
                       pushFlag = 0;
                       break;
                   } else { pushFlag = 0; break;}
               }
               if(pushFlag) { ans.push_back(nums[i]); }
           } else {
               ans.push_back(nums[i]);
           }
        }
        return ans;
    }
};