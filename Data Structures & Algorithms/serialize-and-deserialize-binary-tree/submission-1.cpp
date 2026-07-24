#include <ranges>
using namespace std;

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> res;
        stack<TreeNode*> st;
        st.push(root);
        
        while (!st.empty()) {
            auto* node = st.top();
            st.pop();
            
            if (!node) {
                res.push_back("N");
                continue;
            }
            
            res.push_back(to_string(node->val));
            
            // FIX CRITIC: Punem DREAPTA prima pe stivă!
            // Fiind LIFO, STÂNGA va fi extrasă prima la iterația următoare.
            st.push(node->right);
            st.push(node->left);
        }

        // Echivalentul funcțional cu ranges pentru join_with
        // Unește vectorul res cu virgule
        if (res.empty()) return "";
        return std::accumulate(
            std::next(res.begin()), res.end(), res[0],
            [](string a, string b) { return a + "," + b; }
        );
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> res;
        
        // C++20 views::split generează range-uri pe care le convertim în std::string
        for (auto&& subrange : data | views::split(',')) {
            res.emplace_back(subrange.begin(), subrange.end());
        }

        int i = 0;
        return helper(res, i);
    }

private:
    TreeNode* helper(const vector<string>& v, int& i) {
        if (i >= v.size() || v[i] == "N") {
            i++;
            return nullptr;
        }
        
        auto* node = new TreeNode(stoi(v[i]));
        i++;
        
        node->left = helper(v, i);
        node->right = helper(v, i);
        
        return node;
    }
};