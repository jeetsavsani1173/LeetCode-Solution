class MinStack {
public:// <ele,upto curr min>
    stack<pair<int,int>> stk;
    MinStack() {
        
    }
    
    void push(int val) {
        if(stk.size()==0) stk.push({val,val});
        else{
            stk.push({val,min(val,stk.top().second)});
        }
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;
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