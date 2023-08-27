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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
       
        int length = 0;
        
        ListNode* temp = head;
        while(temp) {
            length++;
            temp = temp->next;
        }
        
        k = k%length;
        
        for(int i=0; i<k; i++) {
            ListNode *lastsNode = head, *lastNode = head;
            
            while(lastsNode->next && lastsNode->next->next) lastsNode = lastsNode->next;
            
            lastNode = lastsNode->next;
            lastNode->next = head;
            lastsNode->next = NULL;
            head = lastNode;
        }
        
        return head;
    }
};