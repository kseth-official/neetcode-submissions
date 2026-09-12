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

    ln* reverseKGroup(ln* head, int k) {
        if (k == 1)
            return head;
        
        vector<ln*> ps;
        ln* curr = head;
        int c = 0;
        ln* temp = nullptr;
        while (curr != nullptr) {
            if (c % k == 0)
                ps.push_back(curr);
            
            if (c % k == k-1)
               temp = curr; 
            c++;
            curr = curr->next;

            // set nullptr after so curr can advance safely above
            if (c % k == 0)
                temp->next = nullptr;
        }

        for (int i=0;i<ps.size();i++) {
            if (c % k !=0 && i == ps.size()-1)
                continue;
            ps[i] = reverse(ps[i]);
        }

        ln* res = nullptr;
        for (auto p: ps) {
            if (res == nullptr) {
                res = p;
                curr = res;
                continue;
            }
            
            while (curr->next != nullptr)
                curr = curr->next;
            curr->next = p;
            curr = p;
        }

        return res;
    }

    ln* reverse(ln* h) {
        ln* p1 = nullptr; 
        ln* p2 = h;
        ln* p3 = nullptr;

        while (p2 != nullptr) {
           p3 = p2->next;
           p2->next = p1;
           p1 = p2;
           p2 = p3; 
        }

        return p1;
    }
};