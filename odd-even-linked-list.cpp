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
     ListNode* oddEvenList(ListNode* head) {
         ListNode* odd = nullptr,
             * even = nullptr,
             * evenStart = nullptr,
             * current = head;
         bool isOdd = true;
         while (current) {
             if (isOdd) {
                 if (odd) {
                     odd->next = current;
                     odd = odd->next;
                 }
                 else {
                     odd = current;
                 }
             }
             else {
                 if (even) {
                     even->next = current;
                     even = even->next;
                 }
                 else {
                     even = current;
                     evenStart = current;
                 }
             }
             current = current->next;
             isOdd ^= true;
         }
         if (evenStart) {
             odd->next = evenStart;
             even->next = nullptr;
         }
         return head;
     }
 };