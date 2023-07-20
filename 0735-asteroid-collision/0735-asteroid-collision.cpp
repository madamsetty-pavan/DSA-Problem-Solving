class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        vector<int> ans;
        bool pushFlag = 1;
        int n = nums.size(), num1, num2;
        for(int i=0;i<n;i++) {
           if(ans.size() && ans.back()>0 && nums[i]<0) {
               pushFlag = 1;
               while(ans.size() && ans.back()>0 && nums[i]<0) {
                   num1 = abs(ans.back()), num2 = abs(nums[i]);
                   if(num1 < num2) {ans.pop_back();}
                   else if(num1 == num2) {
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