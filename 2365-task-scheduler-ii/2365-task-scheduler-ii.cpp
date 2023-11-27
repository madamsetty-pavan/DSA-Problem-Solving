class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long ans = 0;
        unordered_map<long long,long long> mp;
        for(auto &x:tasks) {
            ans++;
            if(mp.find(x) == mp.end()) {
                mp[x] = ans + space +1;
            } else {
                if(ans >= mp[x]) {
                    mp[x] = ans+ space +1;
                } else {
                    ans = mp[x];
                    mp[x] = ans + space+1;
                }
            }
        }
        return ans;
    }
};