class MinStack {
    stack<int> s;
    vector<int> min;
public:
    MinStack() {
        min.push_back(INT_MAX);
    }
    
    void push(int val) {
        if(val<=min.back())
        min.push_back(val);
        s.push(val);
    }
    
    void pop() {
        if(s.top()==min.back())
        min.pop_back();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min.back();
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
