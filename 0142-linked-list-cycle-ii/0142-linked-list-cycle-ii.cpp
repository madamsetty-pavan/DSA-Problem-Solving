/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;
        ListNode* curr = head, *curr2 = head;
        while(curr2 && curr2->next) {
            curr = curr->next;
            curr2 = curr2->next->next;
            if(curr == curr2) break;
        }
        if(!curr2 || !curr2->next) return NULL;
        curr = head;
        while(curr != curr2) {
            curr = curr->next;
            curr2 = curr2->next;
        }
        return curr;
    }
};