class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int low = intervals[0][0], high = intervals[0][1],count=0;
        for(int i=1;i<intervals.size();i++) {
            if(intervals[i][0]<high) {
                high = min(intervals[i][1],high);
                count++;
            } else {
                high = intervals[i][1];
            }
        }
        return count;
    }
};