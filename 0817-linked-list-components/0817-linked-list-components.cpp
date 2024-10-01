/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> st;
        for(int x:nums) {
            st.insert(x);
        }
        ListNode* curr = head;
        int ans = 0;
        while (curr) {
            if(st.find(curr->val) != st.end()) {
                ans++;
                traverseList(curr, st);
            } else {
                curr = curr->next;
            }
        }
        return ans;
    }
    
    void traverseList(ListNode* &curr, unordered_set<int> &st) {
        while(curr) {
            if(st.find(curr->val) == st.end()) {
                return;
            }
            st.erase(curr->val);
            curr = curr->next;
        }
    }
};