class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size()==0) return {};
        vector<int> ans;
        deque<int> dq;
        int i=0,n=nums.size();
        while(i<k)
        {
            while(dq.size() && nums[dq.back()]<=nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            i++;
        }
        ans.push_back(nums[dq.front()]);
        while(i<n)
        {
            while(dq.size() && i-dq.front()+1>k)
            {
                dq.pop_front();
            }
            while(dq.size() && nums[dq.back()]<=nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            ans.push_back(nums[dq.front()]);
            i++;
        }
        return ans;
    }
};