class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        st.push(nums.back());
        for(int i=nums.size()-2;i>=0;i--) {
            int ele = nums[i];
            if(st.top()>ele) {
                st.push(ele);
            } else {
                while(st.size() && st.top()<=ele) {
                    st.pop();
                }
                st.push(ele);
            }
        }
        vector<int> ans;
        for(int i = nums.size()-1;i>=0;i--) {
            int ele = nums[i];
            if(st.top()>ele) {
                ans.push_back(st.top());
            } else {
                while(st.size() && st.top() <= ele) {
                    st.pop();
                }
                if(st.size()==0) {
                    ans.push_back(-1);
                } else {
                    ans.push_back(st.top());
                }
            }
            st.push(ele);
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};