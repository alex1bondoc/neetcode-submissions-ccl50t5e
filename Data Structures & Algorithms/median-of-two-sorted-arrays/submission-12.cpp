class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int left{};
        int right{static_cast<int>(nums1.size())};
        int n{static_cast<int> (nums1.size())};
        int m{static_cast<int> (nums2.size())};
        
        while (left <= right) {
            int fromFirst{left + (right - left) / 2};
            int fromSecond{(n + m) / 2 - fromFirst};
            int max1 = (fromFirst == 0 ? 1 < 31 : nums1[fromFirst - 1]);
            int max2 = (fromSecond == 0 ? 1 << 31 : nums2[fromSecond - 1]);
            int min1 = (fromFirst == n ? 1 << 30 : nums1[fromFirst]);
            int min2 = (fromSecond == m ? 1 << 30 : nums2[fromSecond]);
            std::cout << max1 << " " << min1 << " " << max2 << " " << min2 <<endl;
            if (max1 <= min2 && max2 <= min1) {
                if ((n + m) % 2 == 1) {
                    return std::min(min2, min1);
                }
                else {
                    return (std::min(min1, min2) + std::max(max1, max2)) / 2.0;
                }
            }
            else if (max1 > min2){
                right = fromFirst - 1;
            }
            else {
                left = fromFirst + 1;
            }
        }
        return -1;

    }
};
