class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string sol = "";
        int i = 0;
        int j = 0;
        while (i < word1.size() && j < word2.size()) {
            sol += word1[i];
            sol += word2[j];
            i ++;
            j ++;
        }
        while (i < word1.size()){
            sol += word1[i];
            i ++;
        }

        while (j < word2.size()){
            sol += word2[j];
            j ++;
        }
        return sol;
    }
};