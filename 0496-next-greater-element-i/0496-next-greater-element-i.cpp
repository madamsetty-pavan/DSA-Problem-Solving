class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        mp[nums2.back()] = -1;
        stack<int> st;
        st.push(nums2.back());
        for(int i = nums2.size()-2; i>=0; i--) {
            int ele = nums2[i];
            if(st.top() > ele) {
                mp[ele] = st.top();
                st.push(ele);
            } else {
                while(st.size() && st.top()<ele) {
                    st.pop();
                }
                if(st.size()) {
                     mp[ele] = st.top();
                } else {
                     mp[ele] = -1;
                }
                st.push(ele);
            }
        }
        vector<int> ans;
        for(auto &x:nums1) {
            ans.push_back(mp[x]);
        }
        return ans;
    }
};