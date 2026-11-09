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
    TreeNode* insertAndReturnRoot(TreeNode* root, int val)
    {
        if (!root) return new TreeNode(val);

        if (root->val < val)
        {
            root->right = insertAndReturnRoot(root->right, val);
        }
        else if (root->val > val)
        {
            root->left = insertAndReturnRoot(root->left, val);
        }

        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return insertAndReturnRoot(root, val);
    }
};