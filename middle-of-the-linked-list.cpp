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
    ListNode* middleNode(ListNode* head) {
        ListNode *twoSteps=head, *oneStep=head;
        while (twoSteps->next!=nullptr)
        {
            oneStep=oneStep->next;
            twoSteps=twoSteps->next;
            if (twoSteps->next) twoSteps=twoSteps->next;
        }
        return oneStep;
    }
};