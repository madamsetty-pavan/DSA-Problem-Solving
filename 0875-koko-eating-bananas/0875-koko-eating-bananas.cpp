class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 0, mid;
        for(auto &x:piles) {
            right = max(x,right);
        }
        while(left<right) {
            mid = left + (right -left) /2;
            if(isFeasible(piles,mid,h)) {
                right = mid;
            } else left = mid + 1;
        }
        return left;
    }
    
    bool isFeasible(vector<int>&piles, int mid, int &h) {
        int sum = 0;
        for(auto &x:piles) {
            sum += ceil((double)x/mid);
        }
        return sum<=h;
    }
    
};