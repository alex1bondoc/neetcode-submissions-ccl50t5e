class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left{};
        int right{static_cast<int>(matrix.size() * matrix[0].size()) - 1};
        while (left <= right) {
            int mid{left + (right - left) / 2};
            int row{mid / (int) matrix[0].size()};
            int col{mid % (int) matrix[0].size()};
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] > target) {
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return false;
    }
};
