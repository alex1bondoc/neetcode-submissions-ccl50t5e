class MinStack {
    std::stack<long long> st;
    long long mini{};
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (st.empty()) {
            mini = val;
            st.push(0);
        }
        else {
            st.push(val - mini);
            if (val < mini) {
                mini = val;
            }
        }
    }
    
    void pop() {
        if (st.empty()) return;
        if (st.top() >= 0) {
            st.pop();
        }
        else {
            mini = mini - st.top();
            st.pop();
        }
    }
    
    int top() {
        if (st.empty()) return 0;
        if (st.top() >= 0) return st.top() + mini;
        else return mini;
    }
    
    int getMin() {
        return mini;
    }
};
