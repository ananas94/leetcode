/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node *start=head;
        while (head)
        {
            if (head->child)
            {
                Node *next = head->next;
                head->next = flatten(head->child);
                head->next->prev=head;
                head->child=nullptr;
                
                while (head->next) head = head->next;
                
                head->next = next;
                if (next) next->prev = head;
            }
            head = head->next;
        }
        return start;
    }
};