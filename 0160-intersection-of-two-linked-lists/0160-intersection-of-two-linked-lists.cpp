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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n = 0, m = 0;
        ListNode* curr1 = headA, *curr2 = headB;
        while(curr1){
            n++;
            curr1 = curr1 -> next;
        }
        while(curr2) {
            m++;
            curr2 = curr2 -> next;
        }
        curr1 = headA , curr2 = headB;
        while(n>m) {
                curr1 = curr1 -> next;
                n--;
        }
        while(m>n) {
            curr2 = curr2 -> next;
            m--;
        }
        while(curr1 && curr2 && curr1!=curr2) {
            curr1 = curr1 -> next;
            curr2 = curr2 -> next;
        }
        return curr1;
    }
};