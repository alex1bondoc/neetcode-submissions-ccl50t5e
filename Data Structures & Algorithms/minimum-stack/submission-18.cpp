class MinStack {
    std::stack<long long> nums;
    long long min{};
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (nums.size() == 0) {
            min = val;
            nums.push(0);
        }
        else if (val >= min) {
            nums.push(val - min);
        }
        else {
            nums.push(val - min);
            min = val;
        }
    }
    
    void pop() {
        if (nums.empty()) return;
        if (nums.top() >= 0) {
            nums.pop();
        }
        else {
            long long x{nums.top()};
            nums.pop();
            min = min - x;
        }
    }
    
    int top() {
        if (nums.empty()) return 0;
        if (nums.top() >= 0) {
            return nums.top() + min;
        }
        else {
            long long x{nums.top()};
            return min;
        }
    }
    
    int getMin() {
        return min;
    }
};
