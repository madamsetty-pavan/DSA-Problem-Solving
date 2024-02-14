class DetectSquares {
public:
    map<pair<int,int>,int> countMap;
    unordered_map<int,unordered_set<int>> xCords, yCords;
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        int x = point[0], y = point[1];
        countMap[{x,y}]++;
        yCords[x].insert(y);
        xCords[y].insert(x);
    }
    
    int count(vector<int> point) {
        int x = point[0], y = point[1], ans = 0;
        auto yCor = yCords[x];
        for(auto &newY:yCor) {
            int diff = abs(newY-y);
            if(diff == 0) continue;
            if(countMap.find({x-diff,newY}) != countMap.end() && countMap.find({x-diff,y}) != countMap.end()) {
                ans += (countMap[{x-diff,newY}] * countMap[{x-diff,y}] *countMap[{x,newY}]);
            }
            if(countMap.find({diff+x,newY}) != countMap.end() && countMap.find({x+diff,y}) != countMap.end()) {
                ans += (countMap[{x+diff,newY}] * countMap[{x+diff,y}] *countMap[{x,newY}]);
            }
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */