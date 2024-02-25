class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> leftNear(n, -1), rightNear(n, -1), countArray(n,0);
        int left = -1, right = -1, count = 0;
        for(int i=0;i<n;i++) { 
            if(s[i] == '|') {
                left = i;
                count++;
            }
            countArray[i] = count;
            leftNear[i] = left;
        }
        for(int i=n-1;i>=0;i--) {
            if(s[i] == '|') {
                right = i;
            }
            rightNear[i] = right;
        }
        vector<int> ans;
        for(auto &x:queries) {
            int start = x[0], end = x[1];
            int left = rightNear[start]; 
            int right = leftNear[end];
            if(left == -1 || right == -1 || right<=left) ans.push_back(0);
            else ans.push_back(right-left+1 - (countArray[right] - countArray[left] +1));
        }
        return ans;
    }
};