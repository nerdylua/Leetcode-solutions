/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<TreeNode*> lvl,next_lvl;
        if (root == NULL)
            return {};
        lvl.push_back(root);
        vector<int> ans;
        while (!lvl.empty()) {
            int mx = lvl[0]->val;
            for(auto node: lvl) {
                if (node->left !=  NULL) {
                    next_lvl.push_back(node->left);
                }
                if (node->right != NULL) {
                    next_lvl.push_back(node->right);
                }
                mx = max(node->val, mx);
            }
            ans.push_back(mx);
            swap(lvl, next_lvl);
            while(!next_lvl.empty()) 
                next_lvl.pop_back();
        }
        return ans;
    }
};