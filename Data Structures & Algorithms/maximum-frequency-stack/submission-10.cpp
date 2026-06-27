class FreqStack {
    vector<vector<int>> st;
    unordered_map<int, int> freq;
public:
    FreqStack() {
        st.push_back(vector<int>());
    }
    
    void push(int val) {
        freq[val] ++;
        if (freq[val] == st.size()){
            st.push_back(vector<int>());
        }
        st[freq[val]].push_back(val);
        std::cout << "finish push" << std::endl;
    }
    
    int pop() {
        if (st.back().size() == 0) return 0;
        int solution{st.back().back()}; 
        freq[solution] --;
        st.back().pop_back();
        while (st.size() > 1 && st.back().size() == 0) {
            st.pop_back();
        }
        return solution;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */