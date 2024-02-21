vector<int> findRequestsInQueue(vector<int> wait) {
    vector<int> ans;
    int n = wait.size(), count =n;
    unordered_map<int, vector<int>> mp;
    vector<bool> alive(n, 1);
    for(int i=0;i<n;i++) {
        mp[wait[i]].push_back(i);
    }
    int sec = 0;
    for(int i=0;i<n;i++) {
        count -= mp[sec].size();
        for(auto &x:mp[sec]) {
            alive[x.first] = 0;
        }
        if(alive[i] ==0) {
            ans.push_back(count);
            continue;
        }
        if(wait[i] > sec) {
            ans.push_back(count);
            count--;
        } else {
            count--;
            ans.push_back(count);
        }
        alive[i] = 0;
    }
}

[2, 2, 3, 1]
Output: [4, 2, 1, 0]
Explanation:
