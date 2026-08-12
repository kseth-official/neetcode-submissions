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
        int sz = 0;

        ListNode* curr = head;
        while (curr!=nullptr) {
            sz++;
            curr=curr->next;
        }

        int index_to_remove = sz - n;
        int i = 0;
        curr = head;

        if (i == index_to_remove)
            return curr->next;

        ListNode* prev = curr;
        curr = curr->next;
        i = 1;

        while (curr!=nullptr) {
            if (i == index_to_remove) {
                prev->next = curr->next;
                return head;
            }
            prev = prev->next;
            curr = curr->next;
            i++;
        }
    }
};
