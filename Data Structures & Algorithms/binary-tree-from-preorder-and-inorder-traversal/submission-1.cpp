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
    TreeNode* buildTreeRecursive(vector<int>& preorder, unordered_map<int, int>& idx, int& p, int l, int r) // This is O(n) too, because you are creating a new node, or a new call
    // function for each element in preorder array.
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
        int p = 0;

        unordered_map<int, int> idx; // This is O(n)
        for (int i = 0; i < n; i++) {
            idx[inorder[i]] = i;
        }

        return buildTreeRecursive(preorder, idx, p, 0, n - 1);
    }

    // Overall time complexity O(2n) which is O(n)
    // Overall space complexity, you are creating a new call to
    // recursive function, the space complexity  is whatever
    // input dicates, balanced input O(log n), fully left input 
    // O(n)
    // So total space is O(n) (you could say O(h) for the stack // + O(n) for the map + O(n) for the output).
};
