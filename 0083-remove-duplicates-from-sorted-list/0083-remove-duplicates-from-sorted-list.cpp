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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *n = new ListNode(0, head);
        ListNode *ans = n;
        
        while(n->next) {
            while(n->next->next && n->next->val == n->next->next->val) {
                n->next = n->next->next;
            }
            n = n->next;
        }
        
        return ans->next;
    }
};