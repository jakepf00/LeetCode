class MinStack {
public:
    stack<pair<int, int>> mStack;

    MinStack() {
        
    }
    
    void push(int val) {
        if (mStack.empty()) {
            mStack.push(make_pair(val, val));
        }
        else {
            mStack.push(make_pair(val, min(val, mStack.top().second)));
        }
    }
    
    void pop() {
        mStack.pop();
    }
    
    int top() {
        return mStack.top().first;
    }
    
    int getMin() {
        return mStack.top().second;
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
