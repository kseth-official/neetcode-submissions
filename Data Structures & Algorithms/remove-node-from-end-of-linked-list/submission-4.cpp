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
        ListNode dummy(0, head);
        ListNode* f = head;
        ListNode* s = &dummy;

        for (int i=0;i<n;i++) {
            f = f->next;
        }

        while (f != nullptr) {
            f = f->next;
            s = s->next;
        }

        if (s->next)
            s->next = s->next->next;

        return dummy.next;
    }
};
