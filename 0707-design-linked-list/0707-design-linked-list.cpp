class Node {
 public:
    Node() {
        val = 0;
        next = NULL;
    }
    Node(int v) {
        val = v;
        next = NULL;
    }
    Node(int v, Node *n) {
        val = v;
        next = n;
    }
    int val;
    Node *next;
};
class MyLinkedList {
    Node *head = nullptr;
    int count = 0;
public:
    MyLinkedList() {
        
    }
    
    int get(int index) {
        Node *temp = head;
        while(index-- && temp) temp = temp->next;
        
        if(temp) return temp->val;
        return -1;
    }
    
    void addAtHead(int val) {
        Node *n = new Node(val, head);
        head = n;
        count++;
    }
    
    void addAtTail(int val) {
        if(count == 0) {
            addAtHead(val);
            return;
        }
        
        Node *temp = head, *n = new Node(val);
        while(temp->next) temp = temp->next;
        temp->next = n;
        count++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > count) return;
        
        if(index == 0) {
            addAtHead(val);
            return;
        }        
        if(index == count) {
            addAtTail(val);
            return;
        }
        
        Node *temp = head, *n = new Node(val);
        while(--index) temp = temp->next;
        
        n->next = temp->next;
        temp->next = n;
        
        count++;
    }
    
    void deleteAtIndex(int index) {
        if (index == 0) {
			Node *tmp = head;
			head = head->next;
			count--;
			delete tmp;
			return;
		}

		Node *curr = head, *pre = nullptr;
		while(curr && index > 0) {
			pre = curr;
			curr = curr->next;
			index--;
		}

		if (index == 0 && curr != nullptr) {
			Node *tmp = curr;
			pre->next = curr->next;
			count--;
			delete tmp;
		}
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */