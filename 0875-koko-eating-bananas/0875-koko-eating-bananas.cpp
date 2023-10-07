class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long left = 1, right = 0, mid, totalB = 0;
        for(long long x: piles) {
            right = max(x,right);
            totalB += x;
        }
        while(left<right) {
            mid = left + (right-left)/2;
            if(isFeasibleToComplete(piles,mid,h)) right = mid;
            else left = mid+1;
        }
        return left;
    }
    
    bool isFeasibleToComplete(vector<int>&piles, int mid, int &h){
        long long ans = 0;
        for(auto x:piles) {
            ans += ceil((double)x/mid);
        }
        return ans<=h;
    }
};