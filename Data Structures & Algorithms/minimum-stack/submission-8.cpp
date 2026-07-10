class MinStack {
private:
    stack<long> st;
    int mini = 2147483647;
public:
    
    MinStack() {}
    
    void push(int val) {
        if (st.empty()) {
            st.push(0);
            mini = val;
        }
        else {
            st.push(val - mini);
            if (val < mini) {
                mini = val;
            }
        }
    }
    void pop() {
        if (st.empty()) 
            return;
        if (st.top() >=0) {
            st.pop();
        }
        else {
            mini = mini - st.top();
            st.pop();
        }
    }
    
    int top() {
        if (st.top() > 0) return st.top() + mini;
        else return mini;
    }
    
    int getMin() {
        return mini;
    }
};
