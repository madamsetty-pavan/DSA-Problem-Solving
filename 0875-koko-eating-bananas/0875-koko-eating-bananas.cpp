class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = INT_MIN, mid;
        for(auto &x: piles) {
            right = max(right,x);
        }
        while(left<right) {
            mid = left + (right-left)/2;
            if(isFeasible(piles, mid, h)) right = mid;
            else left = mid+1;
        }
        return left;
    }
    
    bool isFeasible(vector<int>& piles, int mid, int h) {
        int totalHours = 0;
        for(auto &x:piles) {
            totalHours += ceil((double)x/mid);
        }
        return totalHours<=h;
    }
};