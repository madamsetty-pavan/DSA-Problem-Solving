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
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        ListNode* first = mergeSort(head);
        ListNode* second = mergeSort(slow);
        head = merge(first, second);
        return head;
    }
    
    ListNode* merge(ListNode* &first, ListNode* &second) {
        ListNode* ans = new ListNode(), *curr = ans;
        while(first && second) {
            if(first->val <= second->val) {
                curr->next = first;
                first=first->next;
            } else {
                curr->next = second;
                second = second->next;
            }
            curr = curr->next;
        }
        while(first) {
            curr->next = first;
            curr = curr->next;
            first = first->next;
        }
        while(second) {
            curr->next = second;
            curr = curr->next;
            second = second->next;
        }
        return ans->next;
    }
};