class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        std::stack<int> st;
        for (int asteroid : asteroids) {
            bool push{true};
            while (!st.empty() && st.top() > 0 && asteroid < 0) {
                if (st.top() + asteroid == 0) {
                    push = false;
                    st.pop();
                    break;
                }
                else if (st.top() + asteroid > 0) {
                    push = false;
                    break;
                }
                else {
                    st.pop();
                }
            }
            if (push) {
                st.push(asteroid);
            }
        }
        std::vector<int> sol;
        while (st.size()) {
            sol.push_back(st.top());
            st.pop();
        }
        std::reverse(sol.begin(), sol.end());
        return sol;
    }
};