/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, int> imap1;
        unordered_map<int, Node*> imap2;

        Node* curr = head;
        
        int i = 0;
        while (curr) {
            imap1[curr] = i;
            curr = curr->next;
            i++;
        }

        curr = head;
        Node dummy(0);
        Node* copy = &dummy;

        i = 0;
        while (curr) {
            copy->next = new Node(curr->val);
            imap2[i] = copy->next;
            copy = copy->next;
            curr = curr->next;
            i++;
        }

        curr = head;
        copy = dummy.next;
        while (curr) {
            if (imap1.find(curr->random) != imap1.end()) {
                int rand_index = imap1[curr->random];
                copy->random = imap2[rand_index];
            } else {
                copy->random = nullptr;
            }
            curr = curr->next;
            copy = copy->next;
        }

        return dummy.next;
    }
};
