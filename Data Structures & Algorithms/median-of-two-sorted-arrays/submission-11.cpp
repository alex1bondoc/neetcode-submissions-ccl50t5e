class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if (n > m) {
            swap(n, m);
            swap(nums1, nums2);
        }
        int left = 0, right = n;
        while (left <= right) {
            int i = (left + right) / 2;
            int j = (n + m) / 2 - i;
            int nums1Left = i>= 1 ? nums1[i- 1] : -1000001;
            int nums1Right = i < n ? nums1[i] : 1000001;
            int nums2Left = j >= 1 ? nums2[j- 1] : -1000001;
            int nums2Right = j < m ? nums2[j] : 1000001;
          
            cout << nums1Left << " " << nums1Right <<" " << nums2Left <<" " << nums2Right << endl;
            if (nums1Left <= nums2Right && nums2Left <= nums2Right) {
                if ((n + m) % 2 == 0) {
                    return (max(nums1Left, nums2Left) + min(nums1Right, nums2Right)) / 2.0;
                }
                else {
                    return min(nums1Right, nums2Right);
                }
            }
            else if (nums1Left > nums2Right) {
                right = i - 1;
            }
            else {
                left = i + 1;
            }
        }
        return -1;
    }
};
