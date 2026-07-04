class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Folosim deque pentru a putea șterge/accesa de la ambele capete
        deque<int> q; 
        vector<int> solution;
        
        for (int i = 0; i < nums.size(); ++i) {
            // 1. Eliminăm indicii care au ieșit din fereastra curentă (în stânga)
            if (!q.empty() && q.front() == i - k) {
                q.pop_front();
            }
            
            // 2. Eliminăm elementele mai mici din coadă (de la dreapta/back)
            // Pentru că un element mai mic și mai vechi nu are cum să mai fie maxim
            while (!q.empty() && nums[i] > nums[q.back()]) {
                q.pop_back();
            }
            
            // 3. Adăugăm indexul curent
            q.push_back(i);
            
            // 4. Dacă am umplut prima fereastră de dimensiune k, începem să adăugăm la soluție
            if (i >= k - 1) {
                solution.push_back(nums[q.front()]);
            }
        }
        
        return solution;
    }
};