/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tempA = headA, *tempB = headB;
        bool test = false;
        while(tempA != tempB) {
            tempA = tempA->next;
            tempB = tempB->next;
            if(!tempA) {
                if(test) return NULL;
                test = true;
                tempA = headB;
            }
            if(!tempB) {
                tempB = headA;
            }
        }
        
        return tempA;
    }
};