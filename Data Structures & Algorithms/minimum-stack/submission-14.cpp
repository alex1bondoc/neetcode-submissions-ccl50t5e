class MinStack {
    std::stack<int> nums;
    std::stack<int> mins;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        nums.push(val);
        if (mins.size())
            mins.push(std::min(val, mins.top()));
        else {
            mins.push(val);
        }
    }
    
    void pop() {
        if (!nums.size()) return; 
        nums.pop();
        mins.pop();
    }
    
    int top() {
        if (!nums.size()) return 0 ;

        return nums.top();
    }
    
    int getMin() {
        if (!nums.size()) return 0 ;

        return mins.top();
    }
};
