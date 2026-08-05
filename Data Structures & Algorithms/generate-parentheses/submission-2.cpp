#include <vector>
#include <string>

using namespace std;

class Solution {
    vector<string> res;
public:
    vector<string> generateParenthesis(int n) {
        string current = "";
        backtrack(current, n, n);
        return res;
    }
    
    // Trecem 'current' prin REFERINȚĂ (&) pentru a evita copierea în memorie
    void backtrack(string& current, int open, int close) {
        // Condiții de invalidare
        if (close < open || open < 0 || close < 0) return;
        
        // Cazul de bază: am folosit toate parantezele
        if (open == 0 && close == 0) {
            res.push_back(current);
            return;
        }

        // Adăugăm paranteză deschisă '('
        current.push_back('(');
        backtrack(current, open - 1, close);
        current.pop_back(); // Backtrack

        // Adăugăm paranteză închisă ')'
        current.push_back(')');
        backtrack(current, open, close - 1);
        current.pop_back(); // Backtrack
    }
};