class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        if(empty()) return -1;
        
        while(q1.size() != 1) {
            q2.push(q1.front());
            q1.pop();
        }
        
        int t = q1.front();
        q1.pop();
        
        q1 = q2;
        q2 = queue<int> {};
        return t;
    }
    
    int top() {
        if(empty()) return -1;
        
        while(q1.size() != 1) {
            q2.push(q1.front());
            q1.pop();
        }
        
        int t = q1.front();
        q2.push(q1.front());
        
        q1 = q2;
        q2 = queue<int> {};
        return t;
    }
    
    bool empty() {
        return q1.empty();
    }
    private:
        queue<int> q1, q2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */