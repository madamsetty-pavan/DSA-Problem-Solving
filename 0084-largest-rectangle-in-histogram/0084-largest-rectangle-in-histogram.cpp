class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size(), ans = 0, height, index;
        for(int i=0;i<n;i++) {
            if(st.size() && heights[st.top()] <= heights[i]) {
                st.push(i);
                continue;
            }
            while(st.size() && heights[st.top()]>heights[i]) {
                height = st.top();
                st.pop();
                index = st.size() ? st.top() : -1;
                ans = max(ans, (i-index-1) * heights[height]);
            }
            st.push(i);
        }
        
        while(st.size()) {
            height = st.top();
            st.pop();
            index = st.size() ? st.top() : -1;
            ans = max(ans, (n-index-1) * heights[height]);
        }
        return ans;
    }
};