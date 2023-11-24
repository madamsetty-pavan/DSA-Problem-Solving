class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        int n = nums.size(), i = 0;
        while(i< n && i<k) {
            while(dq.size() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i++);
        }
        while(i<n) {
            ans.push_back(nums[dq.front()]);
            while(dq.size() && k < i-dq.front()+1) dq.pop_front();
            while(dq.size() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i++);
        }
        ans.push_back(nums[dq.front()]);
        return ans;
    }
};