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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2) return l1;
        if(!l1) return l2;
        if(!l2) return l1;
        int carry = 0, sum =0;
        ListNode* ans = new ListNode(-1);
        ListNode *curr = ans;
        l1 = reverse(l1);
        l2 = reverse(l2);
        while(l1 && l2) {
            sum = l1->val + l2->val + carry;
            ans -> next = new ListNode(sum%10);
            ans = ans ->next;
            carry = sum/10;

            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1) {
            sum = l1->val + carry;
            carry = sum/10;

            ans -> next = new ListNode(sum%10);
            ans = ans->next;
            l1 = l1->next;
        }

        while(l2) {
            sum = l2->val + carry;
            carry = sum/10;

            ans -> next = new ListNode(sum%10);
            ans = ans->next;
            l2 = l2->next;
        }
        if(carry)  {ans->next = new ListNode(carry); ans = ans->next;}
        ans = reverse(curr->next);
        return ans;
    }

    ListNode* reverse(ListNode* &head) {
        ListNode* curr = head, *next = head->next, *prev = NULL;
        while(curr) {
            next = curr -> next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};