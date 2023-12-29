// recursive solution
class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int costs = 0, ans = INT_MAX;
        for(int i=0;i < baseCosts.size(); i++) {
            recurse(toppingCosts, target, ans, baseCosts[i], 0);
        }
        return ans;
    }
    
    void recurse(vector<int>& toppingCosts, int &target, int &ans, int cost, int index) {
        if(index == toppingCosts.size()) {
            if(abs(target-ans) >= abs(target-cost)) {
                if(abs(target-ans) == abs(target-cost)) {
                    if(ans>cost) ans = cost;
                } else ans = cost;
            }
            return;
        }
        for(int i=0;i<3;i++) {
            recurse(toppingCosts, target, ans, cost + i*toppingCosts[index] , index+1);
        }
    }
};