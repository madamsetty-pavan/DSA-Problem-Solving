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
        ListNode* oddH = head, *evenH = head->next, *oddC = head, *evenC = head->next, *prev;
        while(oddC && oddC->next) {
            evenC = oddC -> next;
            oddC ->next = evenC -> next;
            prev = oddC;
            oddC = oddC -> next;
            if(oddC) evenC->next = oddC->next;
            else evenC->next = NULL;
        }
        if(oddC) {
            oddC -> next = evenH;
        } else {
            prev -> next = evenH;
        }
        return oddH;
    }
    
};