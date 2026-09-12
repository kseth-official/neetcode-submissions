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
    typedef ListNode ln;

    bool isPalindrome(ln* head) {
        if (head->next == nullptr)
            return true;
        
        // 1 2 3 2 1
        // 1 2 2 1
        ln* f = head;
        ln* s = head;
        
        while (f != nullptr && f->next != nullptr) {
            f = f->next->next;
            s = s->next; 
        }

        if (f != nullptr)
            s = s->next; // list length is odd. adjust to point s to midpoint + 1
        
        auto* b = reverse(s);

        while (b != nullptr) {
            if (head->val != b->val)
                return false;
            head = head->next;
            b = b->next;
        }

        return true;
    }

    ln* reverse(ln* head) {
        ln* p1 = nullptr;
        ln* p2 = head;
        ln* p3;

        while (p2 != nullptr) {
            p3 = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p3;
        }

        return p1;
    }
};