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
    void dfs(TreeNode* root, int &depth, int currDepth)
    {
        if (root == nullptr)
            return;
        
        if (currDepth > depth)
            depth = currDepth;
        
        dfs(root->left, depth, currDepth + 1);
        dfs(root->right, depth, currDepth + 1);
    }
    
    void dfs1(TreeNode* root, int &sum, int currDepth, const int &depth)
    {
        if (root == nullptr)
            return;
        
        if (currDepth == depth)
            sum += root->val;
        
        dfs1(root->left, sum, currDepth + 1, depth);
        dfs1(root->right, sum, currDepth + 1, depth);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        int depth = 0;
        dfs(root, depth, 0);
        
        int sum = 0;
        dfs1(root, sum, 0, depth);
        
        return sum;
    }
};