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
    ListNode* removeNthFromEnd(ListNode* head, int n1) {
        int length = 0;
        ListNode *temp = head;
        while(temp) {
            length++;
            temp = temp->next;
        }
        
        // next of length-n+1
        ListNode *n = new ListNode(0, head);
        ListNode *m = n;
        
        int a = length-n1+1;
        
        while(--a) n = n->next;
        if(n->next) n->next = n->next->next;
        
        return m->next;
    }
};