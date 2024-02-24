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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans, nums;
        stack<int> st;
        int count = -1;
        ListNode* curr = head;
        while(curr) {
            while(!st.empty() && curr->val>ans[st.top()]) {
                ans[st.top()] = curr->val;
                st.pop();
            }
            count++;
            st.push(count);
            ans.push_back(curr->val);
            curr = curr->next;
        }
        while(!st.empty()){
            ans[st.top()] = 0;
            st.pop();
        }
        return ans;
    }
};