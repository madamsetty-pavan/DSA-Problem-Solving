class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        int largestTillNow = -1;
        mp[nums2.back()] = -1;
        stack<int> st;
        st.push(nums2.back());
        for(int i = nums2.size()-2; i>=0; i--) {
            if(st.top() > nums2[i]) {
                mp[nums2[i]] = st.top();
                st.push(nums2[i]);
            } else {
                while(st.size() && st.top()<nums2[i]) {
                    st.pop();
                }
                if(st.size()) {
                     mp[nums2[i]] = st.top();
                } else {
                     mp[nums2[i]] = -1;
                }
                st.push(nums2[i]);
            }
        }
        vector<int> ans;
        for(auto &x:nums1) {
            ans.push_back(mp[x]);
        }
        return ans;
    }
};