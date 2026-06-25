class MyStack {
    std::queue<int> stack;
    std::queue<int> helper;

public:
    MyStack() {
        
    }
    
    void push(int x) {
        helper.push(x);
        while (!stack.empty()) {
            helper.push(stack.front());
            stack.pop();         
        }    
        std::swap(stack, helper);
    }
    
    int pop() {
        int sol{stack.front()};
        stack.pop();
        return sol;
    }
    
    int top() {
        return stack.front();
    }
    
    bool empty() {
        return stack.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */