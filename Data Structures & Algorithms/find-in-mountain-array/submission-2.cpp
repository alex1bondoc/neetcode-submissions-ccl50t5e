/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        unordered_map<int, int> mp;
        auto get = [&mp](MountainArray& mA, int index) {
            if (mp.contains(index)) return mp[index];
            mp[index] = mA.get(index);
            return mp[index];
        };
        int left{1};
        int right{mountainArr.length() - 2};
        int peak{};
        while (left <= right) {
            int mid{left + (right -  left) / 2};
            int m1{get(mountainArr, mid - 1)};
            int m2{get(mountainArr, mid)};
            int m3{get(mountainArr, mid + 1)};
            if (m1 < m2 && m2 < m3) {
                left = mid + 1;
            }
            else if (m1 > m2 && m2 > m3) {
                right = mid - 1;
            }
            else {
                peak = mid;
                left = right + 1;
            }
        } 
        left = 0;
        right = peak;
        while (left <= right) {
            int mid{left + (right - left) / 2};
            int nr{get(mountainArr, mid)};
            if (nr == target) return mid;
            else if(nr < target) left = mid + 1;
            else right = mid - 1;
        }
        left = peak;
        right = mountainArr.length() - 1;
        while (left <= right) {
            int mid{left + (right - left) / 2};
            int nr{get(mountainArr, mid)};
            if (nr == target) return mid;
            else if (nr < target) {
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return -1;
    }
};