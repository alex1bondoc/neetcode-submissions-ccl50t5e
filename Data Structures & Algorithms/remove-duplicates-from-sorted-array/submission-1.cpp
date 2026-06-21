class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (i == 0 || nums[i] != nums[cnt - 1]){
                nums[cnt++] = nums[i]; 
            }
            
        }
        return cnt;
    }
};