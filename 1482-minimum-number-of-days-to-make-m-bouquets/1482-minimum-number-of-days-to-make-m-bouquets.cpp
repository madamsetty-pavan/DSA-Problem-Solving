class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long left = INT_MAX, right = INT_MIN, mid;
        for(long long x:bloomDay) {
            left = min(left,x);
            right = max(right, x);
        }
        while(left<right) {
            mid = left + (right-left)/2;
            if(isFeasible(bloomDay, mid, k,m)) right = mid;
            else left = mid+1;
        }
        if(isFeasible(bloomDay, left, k,m )) return left;
        return -1;
    }
    
    
    bool isFeasible(vector<int>&bloomDay, int mid, int k, int m) {
        int count = 0, bouq = 0;
        for(auto x:bloomDay) {
            if(x<=mid) {
                count++;
            } else count = 0;
            if(count==k) {
                bouq++;
                count = 0;
            }
        }
        return bouq>=m;
    }
};