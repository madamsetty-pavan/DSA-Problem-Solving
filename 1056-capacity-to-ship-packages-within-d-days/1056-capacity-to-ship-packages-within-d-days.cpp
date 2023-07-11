class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left =0, right = 0, mid;
        for(auto x:weights) {
            left =  max(left,x);
            right +=x;
        }
        while(left<right)  {
            mid = left +(right-left)/2;
            if(isFeasible(weights, mid, days)) right = mid;
            else left = mid+1;
        }
        return left;
    }

    bool isFeasible(vector<int> & weights,int capacity, int givenDays) {
        int days = 1, sum =0;
        for(int i=0;i<weights.size();i++) {
            sum += weights[i];
            if(sum>capacity) {
                days++;
                sum = weights[i];
                if(days>givenDays) return false;
            }
        }
        return true;
    }
};