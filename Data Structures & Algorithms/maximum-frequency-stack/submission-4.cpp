class FreqStack {
    std::unordered_map<int, int> map;
    int maxi{};
    std::vector<std::stack<int>> stacks; 

public:
    FreqStack() {
        stacks.resize(30000);
    }
    
    void push(int val) {
        map[val] ++;
        maxi = std::max(maxi, map[val]);
        stacks[map[val]].push(val);
    }
    
    int pop() {
        if (maxi == 0) return 0;
        
        int sol{stacks[maxi].top()};
        stacks[maxi].pop();
        map[sol]--;
        while(maxi > 0 && stacks[maxi].size() == 0) maxi --;
        return sol;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */