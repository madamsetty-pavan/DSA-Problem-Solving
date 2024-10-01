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
        unordered_set<int> st, st2;
        for(int x:nums) {
            st.insert(x);
        }
        ListNode* curr = head;
        int ans = 0;
        while (curr) {
            if(st.find(curr->val) != st.end() && st2.find(curr->val) ==st2.end()) {
                ans++;
                traverseList(curr, st, st2);
            } else {
                curr = curr->next;
            }
        }
        return ans;
    }
    
    void traverseList(ListNode* &curr, unordered_set<int> &st, unordered_set<int> &st2) {
        while(curr) {
            if(st.find(curr->val) == st.end() || st2.find(curr->val) != st2.end()) {
                return;
            }
            st2.insert(curr->val);
            curr = curr->next;
        }
    }
};