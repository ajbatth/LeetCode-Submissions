class MinStack {
public:
    stack<int>s,ms;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(ms.empty()) ms.push(val);
        else if(ms.top()>=val)ms.push(val);
    }
    
    void pop() {
        if(!s.empty() && ms.top()==s.top()){
            s.pop();
            ms.pop();
        }
        else if(!s.empty())s.pop();
        
    }
    
    int top() {
        return s.top();
        
    }
    
    int getMin() {
        return ms.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */