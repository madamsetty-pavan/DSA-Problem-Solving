class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size(),maxNum = arr[n-1];
        vector<int> ans(n,-1);
        for(int i=n-2; i>=0;i--) {
            ans[i] = maxNum;
            maxNum= max(arr[i],maxNum);
        }
        return ans;
    }
};