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
void dfs(TreeNode* node, int ma, int mi, int &ans){
    if (node->val > ma)
        ma = node->val;
    if (node->val < mi)
        mi = node->val;
    
    if (ma - mi > ans)
        ans = ma - mi;
    
    if (node->left != nullptr)
        dfs(node->left, ma, mi, ans);
    if (node->right != nullptr)
        dfs(node->right, ma, mi, ans);  
}
public:
    int maxAncestorDiff(TreeNode* root) {
        int ma = root->val;
        int mi = root->val;
        int ans = 0;
        dfs(root, ma, mi, ans);
        return ans;
    }
};