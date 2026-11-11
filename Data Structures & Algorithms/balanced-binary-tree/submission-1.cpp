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
   private:
    pair<bool, int> isBalancedNode(TreeNode* root) {
        if (!root) return {true, 0};
        pair<bool, int> leftBranch = isBalancedNode(root->left);
        pair<bool, int> rightBranch = isBalancedNode(root->right);

        bool isBalanced = (leftBranch.first && rightBranch.first) &&
                          (abs(leftBranch.second - rightBranch.second) <= 1);
        int height = 1 + max(leftBranch.second, rightBranch.second);

        return {isBalanced, height};
    }

   public:
    bool isBalanced(TreeNode* root) {
        return isBalancedNode(root).first;
    }
};
