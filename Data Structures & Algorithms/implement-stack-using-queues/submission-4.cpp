class MyStack {
    std::queue<int> stack;
    std::queue<int> helper;
public:
    MyStack() {}
    
    void push(int x) {
        helper.push(x);
        while (stack.size()) {
            helper.push(stack.front());
            stack.pop();
        }
        std::swap(helper, stack);
    }
    
    int pop() {
        int x{stack.front()};
        stack.pop();
        return x;
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