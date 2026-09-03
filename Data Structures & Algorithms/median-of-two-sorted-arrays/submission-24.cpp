class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) swap(nums1, nums2);
        int n{static_cast<int>(nums1.size())};
        int m{static_cast<int>(nums2.size())};
        int need{(n + m) / 2 + (n + m) % 2};
        int mini{1 << 31};
        int maxi{1 << 30};
        // i = number of elements from first
        // j = number of elemnts form the second
        int l{0};
        int r{n};
        while (l <= r) {
            int i{(r - l) / 2 + l};
            int j{need - i};
            int leftA{(i == 0) ? mini : nums1[i - 1]};
            int rightA{(i == n) ? maxi : nums1[i]};
            int leftB{(j == 0) ? mini : nums2[j - 1]};
            int rightB{(j == m) ? maxi : nums2[j]};
            cout << leftA << " " << rightA << " " << leftB <<" " << rightB << endl;

            if (leftA <= rightB && leftB <= rightA) {
                if ((n + m) % 2) {
                    return max(leftA, leftB);
                }
                else {
                    return 0.5 * (max(leftA, leftB) + min(rightA, rightB));
                }
            } 
            else if (leftA > rightB) {
                r = i - 1;
            }
            else {
                l = i + 1;
            }
        }
        return 0.0;
    }
};
