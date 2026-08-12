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
        ListNode dummy;
        ListNode* sum = &dummy;

        int carry = 0;
        int ones_place;
        
        while (l1 || l2) {
            if (!l1) {
                ones_place = (l2->val + carry) % 10;
                carry = (l2->val + carry) / 10;
                l2 = l2->next;
            } else if (!l2) {
                ones_place = (l1->val + carry) % 10;
                carry = (l1->val + carry) / 10;
                l1 = l1->next;
            } else {
                ones_place = (l1->val + l2->val + carry) % 10;
                carry = (l1->val + l2->val + carry) / 10;
                l1 = l1->next;
                l2 = l2->next;
            }

            sum->next = new ListNode(ones_place);
            sum = sum->next;
        }

        if (carry > 0) {
            sum->next = new ListNode(carry);
        }

        return dummy.next;
    }
};
