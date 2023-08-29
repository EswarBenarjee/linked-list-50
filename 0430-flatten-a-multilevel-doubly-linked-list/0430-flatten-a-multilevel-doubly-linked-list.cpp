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
        if(!head) return head;
        
        Node *temp = head;
        while(temp) {
            if(temp->child) {
                Node *n = temp->next;
                
                temp->next = flatten(temp->child);
                temp->next->prev = temp;
                
                temp->child = nullptr;
                
                while(temp->next) {
                    temp = temp->next;
                    temp->child = nullptr;
                }
                temp->next = n;
                
                if(n) n->prev = temp;
            }
            
            temp->child = nullptr;
            temp = temp->next;
        }
        
        return head;
    }
};