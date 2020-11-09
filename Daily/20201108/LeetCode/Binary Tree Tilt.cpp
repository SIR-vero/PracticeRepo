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
int dfs(TreeNode* root, int &sum){
    
    int v1 = 0, v2 = 0;
    if (root->left != nullptr)
        v1 = dfs(root->left, sum);
    if (root->right != nullptr)
        v2 = dfs(root->right, sum);
    
    sum += (v1 > v2) ? v1-v2 : v2-v1;
    return v1+v2+root->val;
}
public:
    int findTilt(TreeNode* root) {
        int ans = 0;
        if (root == nullptr)
            return 0;
        int t = dfs(root, ans);
        return ans;
    }
};