class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int left{}, right{static_cast<int>(points.size() - 1)};
        int pivot{static_cast<int>(points.size())};
        while (k != pivot) {
            int l{left};
            int compare{euclidean(points[right])};
            for (int r{left}; r < right; ++r) {
                if (euclidean(points[r]) < compare) {
                    swap(points[l], points[r]);
                    l++;
                }
            }
            swap(points[right], points[l]);
            pivot = l;
            if (pivot < k) left = pivot + 1;
            else if (pivot > k) right = pivot - 1;
        }
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }

private:

    int euclidean(vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    }
};