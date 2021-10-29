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
        ListNode* root = new ListNode();
        ListNode *next = root;
        int move = 0;
        while (next)
        {
            int x = l1 ? l1->val : 0;
            l1 = l1 ? l1->next : nullptr;
            int y = l2 ? l2->val : 0;
            l2 = l2 ? l2->next : nullptr;
            next->val = (x+y+move) % 10;
            move = (x+y+move) / 10;
            if (move || l1 || l2)
            {
                next->next = new ListNode();
            }
            next = next->next;
            
        }
        return root;
    }
};