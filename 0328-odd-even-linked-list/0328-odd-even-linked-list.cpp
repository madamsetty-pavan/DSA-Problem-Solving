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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        ListNode* odd = head, *even = head->next, *prev= NULL, *curr1 = head, *curr2 = even;
        while(curr1 && curr1-> next) {
            prev = curr1;
            curr1->next = curr2->next;
            if(curr1->next) {
                curr2 -> next = curr1 ->next ->next;
            } else curr2->next = NULL;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        if(prev) {
            if(prev->next) prev = prev->next;
            prev->next = even;
        } 
        return head;
    }
};