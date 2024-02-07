class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> st;
        int n = rooms.size();
        for(int i=0;i<n;i++) {
            st.insert(i);
        }
        recurse(rooms, st, 0);
        return st.empty();
    }
    
    void recurse(vector<vector<int>>& rooms, unordered_set<int>&st, int index) {
        if(st.find(index) == st.end()) return;
        st.erase(index);
        for(int i=0;i<rooms[index].size();i++) {
            recurse(rooms, st, rooms[index][i]);
        }
    }
};