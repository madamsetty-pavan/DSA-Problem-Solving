class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> buffer;
        vector<bool> freq(nums.size(),0);
        recurse(nums, buffer, ans, freq);
        return ans;
    }
    
    void recurse(vector<int>&nums, vector<int>&buffer, vector<vector<int>>&ans, vector<bool>&freq) {
        if(nums.size()==buffer.size()) {
            ans.push_back(buffer);
            return;
        }
        for(int i=0;i<nums.size();i++) {
            if(!freq[i]) {
                freq[i] = 1;
                buffer.push_back(nums[i]);
                recurse(nums,buffer,ans,freq);
                buffer.pop_back();
                freq[i]=0;
            }
        }
    }
};