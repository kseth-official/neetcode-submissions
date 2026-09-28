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
        // 0 1 2 3 4 5
        // n = 4
        // 2 removed
        // index = 2
        // max index = 6
        int l =0;
        auto* curr = head;
        while (curr != nullptr) {
            curr = curr->next;
            l++;
        }

        if (n == l)
            return head->next;

        curr = head;
        for (int i=0;i<l-n-1;i++) {
            curr = curr->next;
        }

        if (curr->next) 
            curr->next = curr->next->next;
        
        return head;
    }
};
