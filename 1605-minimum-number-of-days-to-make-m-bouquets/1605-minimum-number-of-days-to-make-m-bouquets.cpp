class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int left = INT_MAX, right =INT_MIN, mid;
        for(auto x:bloomDay) {
            left = min(left,x);
            right = max(right,x);
        }
        while(left<right) {
            mid = left +(right-left)/2;
            if(isFeasible(bloomDay, mid, k, m)) right = mid;
            else left = mid +1;
        }
        if(isFeasible(bloomDay, left, k, m)) return left;
        return -1;
    }

    bool isFeasible(vector<int> bloomDay, int mid, int k, int m) {
        for(auto &x:bloomDay) {
            if(x>mid) x = -1;
        }
        int sum = 0, ans = 0;
        for(auto x:bloomDay) {
            if(x!= -1) sum++;
            if(sum==k || x==-1) {
                if(sum==k) ans++;
                sum = 0;
            }
        }
        return ans>=m;
    }
};