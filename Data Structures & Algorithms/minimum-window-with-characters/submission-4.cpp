#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        // Înlocuim unordered_map cu vectori ficși de dimensiune 128 (toate caracterele ASCII)
        vector<int> freq(128, 0);
        vector<int> freq2(128, 0);
        
        int need{0};
        int minLength = INT_MAX;
        int start{-1};
        
        for (char c : t) {
            if (freq[c] == 0) need++;
            freq[c]++;
        }
        
        int left{};
        for (int right{}; right < s.size(); ++right) {
            char r_char = s[right];
            
            if (freq[r_char] != 0) {
                freq2[r_char]++;
                // Scădem din 'need' doar când frecvența curentă o egalează PE CEA EXACTĂ din t
                if (freq2[r_char] == freq[r_char]) {
                    need--;
                }
            }
            
            while (need == 0) {
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    start = left;
                }
                
                char l_char = s[left];
                if (freq[l_char] != 0) {
                    // Dacă eliminarea caracterului strică potrivirea perfectă, incrementăm 'need'
                    if (freq2[l_char] == freq[l_char]) {
                        need++;
                    }
                    freq2[l_char]--;
                }
                left++;
            }
        }
        
        if (start == -1) return "";
        // FIX: Al doilea parametru este doar lungimea, nu indexul final!
        return s.substr(start, minLength); 
    }
};