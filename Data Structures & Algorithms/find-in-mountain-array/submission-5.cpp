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
        std::unordered_map<int, int> cache;
        auto get = [&mountainArr, &cache](int index) {
            if (!cache.contains(index))
                cache[index] = mountainArr.get(index);
            return cache[index];
        };
        int n{mountainArr.length()};
        int left{1};
        int right{n - 2};
        int index{};
        while (left <= right) {
            int mid{left + (right - left) / 2};
            int prev{get(mid - 1)};
            int cur{get(mid)};
            int next{get(mid + 1)};
            if (prev < cur && cur > next){
                index = cur;
                break;
            }
            else if (prev < cur && cur < next){
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        auto binarySearch = [&mountainArr, &cache, &get](int left, int right,int target, bool desc=false) {
            while (left <= right) {
                int mid{left + (right - left) / 2};
                if (get(mid) == target) return mid;
                if (!desc && get(mid) < target || desc && get(mid) > target) {
                    left = mid + 1;
                }
                else right = mid - 1;
            }
            return -1;
        };
        int res{binarySearch(0, index, target)};
        if (res != -1) return res;
        return binarySearch(index, n - 1, target, true);
    }
};