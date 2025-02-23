class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        if (preorder.empty()) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        if (preorder.size() == 1) return root;

        int leftSubtreeSize = 0;
        for (int i = 0; i < postorder.size(); i++) {
            if (postorder[i] == preorder[1]) {
                leftSubtreeSize = i + 1;
                break;
            }
        }
        vector<int> leftPre(preorder.begin() + 1, preorder.begin() + 1 + leftSubtreeSize);
        vector<int> rightPre(preorder.begin() + 1 + leftSubtreeSize, preorder.end());
        vector<int> leftPost(postorder.begin(), postorder.begin() + leftSubtreeSize);
        vector<int> rightPost(postorder.begin() + leftSubtreeSize, postorder.end() - 1);
        root->left = constructFromPrePost(leftPre, leftPost);
        root->right = constructFromPrePost(rightPre, rightPost);

        return root;
    }
};