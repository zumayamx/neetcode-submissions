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
 *
 * Okay, the idea is to do DFS approach and mantain a list
 * with the nodes that accomplish certain conditions.
 * That conditions are, not to be a null node, and the sum of all
 * acumulated needs to be less than the target.
 * I think, it doesn't make sense to keep exploring a path, which
 * it's acumulated sum is greater than the target.
 *
 * So, the approach is to travel from the root, to the left and right
 * subtrees recursively, in each step, check the following:
 * 
 *  1. If the root is not nullptr or the acumulated sum so far is not
 *     greater than the target.
 *  2. Add the root value to path list.
 *  3. Check if the root is a leaft node (left and right are null), if it is
 *     check if the acumulated sum is equal to the target, in that case return true.
 *  4. Call the recursive function on the left subtree, if that call returns true
 *     that means is a valid path, so pass up the result (true) through the recursive tree
 *  5. Call the recursive function on the right subtree, and the same case ocurrs.
 *  6. If step 4 or 5 were not met, that means it does not exists a valid path from the current
 *     root node, so pop it from the path list.
 *  7. Finally return false if dont exists a valid path from the root node.
 *
 */
class Solution {
private:
    int pathSum(vector<int>& path)
    {
        int sum = 0;
        for (int& e : path)
        {
            sum += e;
        }
        return sum;
    }
    bool leafPath(TreeNode* root, vector<int>& path, int target)
    {
        if (!root) return false;
        path.push_back(root->val);
        if ((!root->left && !root->right) && pathSum(path) == target) return true;
        if (leafPath(root->left, path, target)) return true;
        if (leafPath(root->right, path, target)) return true;
        path.pop_back();
        return false;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        return leafPath(root, path, targetSum);
    }
};