class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(auto x: arr) {
            mp[((x%k) + k)%k]++;
        }
        for(int i=0; i<=k/2; i++) {
            int rem = (i % k + k) % k;
            if(rem == 0 && mp[rem]%2 !=0) return false;
            if(mp[rem] != mp[(k-rem)%k]) {
               return false;
            } 
        }
        return true;
    }
};