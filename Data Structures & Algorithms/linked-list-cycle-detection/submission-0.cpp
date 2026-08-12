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
    bool hasCycle(ListNode* head) {
        ListNode* first = head;
        ListNode* second = head;

        if (!head->next) {
            return false;
        }

        while (first->next) {
            if (!second->next->next || !first->next) {
                return false;    
            } 

            first = first->next;
            second = second->next->next;

            if (first == second) {
                return true;
            }
        }

        return false;
    }
};
