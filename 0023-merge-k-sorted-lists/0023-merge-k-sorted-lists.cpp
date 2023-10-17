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

struct comparator {
    bool operator()(ListNode* &a, ListNode* &b) {
        return a->val>b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comparator> pq;
        for(int i=0;i<lists.size();i++) {
            if(lists[i]) pq.push(lists[i]);
        }
        ListNode* ans = new ListNode(), *curr = ans;
        while(pq.size()) {
            ListNode* temp = pq.top();
            pq.pop();
            curr->next = temp;
            curr = curr->next;
            temp = temp->next;
            if(temp) pq.push(temp);
        }
        return ans->next;
    }
};