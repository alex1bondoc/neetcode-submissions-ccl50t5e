class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    KthLargest(int k, vector<int>& nums) {
        for (const auto& n : nums) {
            if (pq.size() == k) {
                pq.pop();
            }
            pq.push(n);
        }
    }
    
    int add(int val) {
        if (pq.size() && pq.top() < val) {
            pq.pop();
        }
        pq.push(val);

        return pq.top();
    }
};
