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
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
    
    ListNode* mergeSort(ListNode* &head) {
        if(!head || !head->next) return head;
        ListNode* slow = head, *fast = head, *prev = NULL;
        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast -> next -> next;
        }
        prev -> next = NULL;
        ListNode* firstHalf = mergeSort(head);
        ListNode* secondHalf = mergeSort(slow);
        return merge(firstHalf, secondHalf);
    }
    
    ListNode* merge(ListNode* &firstHalf, ListNode* &secondHalf) {
        ListNode* answer = new ListNode(), *ans = answer;
        while(firstHalf && secondHalf) {
            if(firstHalf->val<secondHalf->val) {
                answer -> next = firstHalf;
                firstHalf = firstHalf -> next;
            } else {
                answer -> next = secondHalf;
                secondHalf = secondHalf -> next;
            }
            answer = answer-> next;
        }
        if(firstHalf) {
            answer -> next = firstHalf;
        }
        if(secondHalf) {
            answer -> next = secondHalf;
        }
        return ans->next;
    }
};