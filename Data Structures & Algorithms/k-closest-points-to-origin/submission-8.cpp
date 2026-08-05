class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto euclid = [](vector<int> point) {
            return point[0] * point[0] + point[1] * point[1];
        };
        int left{}, right{static_cast<int>(points.size() - 1)};
        int pivot{static_cast<int>(points.size())};
        while (pivot != k) {
            int compare{euclid(points[right])}, l{left};
            for (int r{left}; r < right; ++r) {
                if (euclid(points[r]) < compare) {
                    swap(points[r], points[l]);
                    l++;
                }
            }
            swap(points[right], points[l]);
            pivot = l;
            if (pivot < k) {
                left = pivot + 1;
            }
            else if (pivot > k) {
                right = pivot - 1;
            }
        }
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};