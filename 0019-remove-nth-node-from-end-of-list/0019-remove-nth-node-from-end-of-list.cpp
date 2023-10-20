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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        ListNode* slow = head, *fast = head;
        while(n>0) {
            fast = fast -> next;
            --n;
        }
        if(!fast) return head->next;
        while(fast && fast->next) {
            slow = slow -> next;
            fast = fast-> next;
        }
        slow -> next = slow -> next -> next;
        return head;
    }
};