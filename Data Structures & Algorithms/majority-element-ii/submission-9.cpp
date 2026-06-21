class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cand1 = 1000000000, cand2 = 1000000000;
        int app1{0}, app2{0};
        for (int i = 0; i <nums.size(); ++i){
            if (nums[i] == cand1) {
                app1 ++;
            }
            else if (nums[i] == cand2) {
                app2 ++;
            }
            else {
                app2 --;
                if (app2 < 0) {
                    cand2 = nums[i];
                    app2 = 1;
                }
            }
            if (app2 >  app1) {
                swap(cand1, cand2);
                swap(app2, app1);
            }
        }
        std::vector<int> sol;
        app1 = 0, app2 = 0;
        for (int i = 0; i< nums.size(); ++i) {
            if (nums[i] == cand1) {
                app1 ++;
            }
            else if (nums[i] == cand2) app2++;
        }
        if (app1 > nums.size() / 3) sol.push_back(cand1);
        if (app2 > nums.size() / 3) sol.push_back(cand2);
        return sol;
    }
};