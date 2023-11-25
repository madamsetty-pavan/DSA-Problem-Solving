// My own solution which is not working
// class Solution {
// public:
//     struct Compare {
//         bool operator()(const pair<int, int>& x, const pair<int, int>& y) const {
//             if (x.second == y.second)
//                 return x.first < y.first;
//             return x.second > y.second;
//         }
//     };   
//     int leastInterval(vector<char>& tasks, int n) {
//         priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
//         unordered_map<char,int> mp;
//         for(auto &x: tasks) {
//             mp[x]++;
//         }
//         for(auto x=mp.begin();x!=mp.end();x++) {
//             pq.push({x->second, 0});
//         }
//         int ans = 0, count = 0;
//         while (pq.size()) {
//             ans++;
//             auto x = pq.top();
//             cout<<x.first<< " "<<x.second<<" "<<ans<<endl;
//             if(x.second > ans) {
//                 cout<<"inside "<<x.first<< " "<<x.second<<endl;
//                 continue;
//             }
            
//             x.second = ans+n+1;
//             x.first--;
//             pq.pop();
//             if(x.first > 0) pq.push(x);
//         }
//         return ans;
//     }
// };

// priority queue based
// class Solution {
//     public: 
//         int leastInterval(vector<char>&tasks, int n) {
//             unordered_map<char, int> mp;
//             priority_queue<int> pq;
//             for (auto &x:tasks) {
//                 mp[x]++;
//             }
//             for (auto &x: mp) {
//                 pq.push(x.second);
//             }
//             int ans = 0;
//             while(pq.size()) {
//                 vector<int> temp;
//                 int cycle = n+1;
//                 while(cycle>0 && pq.size()) {
//                     auto x = pq.top();
//                     pq.pop();
//                     if(x>1) {
//                         temp.push_back(--x);
//                     }
//                     ans++;
//                     cycle--;
//                 }
                
//                 for(auto &x:temp) {
//                     pq.push(x);
//                 }
//                 if(pq.size()==0) break;
//                 ans += cycle;
//             }
//             return ans;
//         }
// };

class Solution {
    public:
    int leastInterval(vector<char>&tasks, int n) {
        unordered_map<int,int> mp;
        int maxFreq = 0, countMaxFreq = 0;
        for(auto &x:tasks) {
            mp[x]++;
            maxFreq = max(maxFreq, mp[x]);
        }
        for(auto &x:mp) {
            if(x.second == maxFreq) countMaxFreq++; 
        }
        int ans = (maxFreq-1) *(n+1) + countMaxFreq;
        if(ans>tasks.size()) return ans;
        return tasks.size();
    }
};