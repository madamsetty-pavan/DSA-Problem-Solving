class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> st;
        recurse(rooms, st, 0);
        return st.size() == rooms.size();
    }
    
    void recurse(vector<vector<int>>& rooms, unordered_set<int>&st, int index) {
        if(st.find(index) != st.end()) return;
        st.insert(index);
        for(int i=0;i<rooms[index].size();i++) {
            recurse(rooms, st, rooms[index][i]);
        }
    }
};