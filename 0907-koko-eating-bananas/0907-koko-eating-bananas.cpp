class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1, right =0, mid;
        for(auto x:piles) {
            right = max(right, x);
        }
        while(left<right) {
            mid = left + (right-left)/2;
            if(isFeasible(mid,h, piles)) right = mid;
            else left = mid+1;
        }
        return left;
    }

    bool isFeasible(int speed, int threshold, vector<int>&piles) {
       int sum = 0;
       for(float x:piles) {
           sum += ceil((double)x/speed);
       }
       return sum<=threshold;
    }
};
