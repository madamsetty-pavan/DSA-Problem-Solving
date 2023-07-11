class Solution {
public:
    int mySqrt(int x) {
        long long left = 0, right = (long long)x + 1, mid;
        while(left<right) {
            mid = left + (right-left)/2;
            if((mid*mid) > x) {
                right = mid;
            } else left = mid+1;
        }
        return left-1;
    }
};