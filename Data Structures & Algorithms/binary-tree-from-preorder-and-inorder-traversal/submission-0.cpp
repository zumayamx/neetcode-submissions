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
    TreeNode* buildTreeRecursive(vector<int>& preorder, unordered_map<int, int>& idx, int& p, int l, int r) 
    {
        if (l > r) return nullptr;
        int rootValue = preorder[p];
        TreeNode* curr = new TreeNode(rootValue);
        p++;

        int m = idx[rootValue];
        curr->left = buildTreeRecursive(preorder, idx, p, l, m - 1);
        curr->right = buildTreeRecursive(preorder, idx, p, m + 1, r);

        return curr;

    }

   public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();

        unordered_map<int, int> idx;
        for (int i = 0; i < n; i++) {
            idx[inorder[i]] = i;
        }
        int p = 0;
        return buildTreeRecursive(preorder, idx, p, 0, n - 1);
    }
};
