class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int left = 1, right = 1e7, mid;
        while(left<right) {
            mid = left + (right-left)/2;
            if(isFeasible(dist,hour, mid)) right = mid;
            else left = mid+1;
        }
        if(isFeasible(dist,hour,left))
                return left;  
        else return -1;
    }
    
    bool isFeasible(vector<int>& dist, double &hour, int mid) {
        double time = 0;
        for(int i=0;i<dist.size()-1;i++) {
            time += ceil((double)dist[i]/mid);
        }
        time += (double) dist.back()/mid;
        return (time<=hour);
    }
};