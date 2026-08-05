class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (maxHeap.size() == minHeap.size()) {
            maxHeap.push(num);
        }
        else {
            minHeap.push(num);
            
        }
        if (minHeap.size() && minHeap.top() < maxHeap.top()) {
                minHeap.push(maxHeap.top());
                maxHeap.push(minHeap.top());
                minHeap.pop();
                maxHeap.pop();
            }
    }
    
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        return maxHeap.top();
    }
};
