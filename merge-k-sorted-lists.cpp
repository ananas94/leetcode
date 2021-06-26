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
private:
    ListNode* merge(ListNode* first, ListNode* second)
    {
        ListNode *output,*it1,*it2;
        if (first && second && first->val <second->val )
        {
            output = first;
            it1=first;
            it2=second;
        }
        else
        {
            output = second;
            it1 = second;
            it2 = first;    
        }
        while (it1 != nullptr || it2 != nullptr){
            if (it1 == nullptr)
                return it2;
            if (it2 == nullptr)
                return output;
            if (it1 && it1->next == nullptr ){
                it1->next=it2;
                return output;
            }
            if (it1 && it2 && it1->next->val > it2->val)
            {
                ListNode* insert = it2;
                it2=it2->next;
                insert->next = it1->next;
                it1->next=insert;
            }
            if (it1 && it2 && it1->next->val <= it2->val) 
            {
                it1=it1->next;
            }
        }
        return output;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *output = nullptr;
        for (auto l: lists) {
            output = merge(output,l);
        }
        return output;
    }
};