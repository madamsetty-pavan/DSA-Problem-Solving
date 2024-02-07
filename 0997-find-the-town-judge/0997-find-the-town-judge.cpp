class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<pair<int,int>> inPairs(n,{0,0});
        for(auto &x:trust) {
            inPairs[x[1]-1].first++;
            inPairs[x[0]-1].second++;
        }
        for(int i=0;i<n;i++) {
            if(inPairs[i].first==n-1 && inPairs[i].second == 0) return i+1;
        }
        return -1;
    }
};