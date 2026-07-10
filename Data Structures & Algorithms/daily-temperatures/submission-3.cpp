class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<int> st;
        std::vector<int> sol(temperatures.size(), 0);
        for (int i{}; i < temperatures.size(); ++i) {
            while(!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                int pos{st.top()};
                sol[pos] = i - pos;
                st.pop(); 
            }
            st.push(i);   
        }
        return sol;
    }
};
