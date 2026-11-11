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
    void inorderTraversal(TreeNode* root, vector<int>& arr)
    {
        if (!root) return;
        inorderTraversal(root->left, arr);
        arr.push_back(root->val);
        inorderTraversal(root->right, arr);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> sortedElements;
        inorderTraversal(root, sortedElements);
        return sortedElements[k - 1];
    }
};
