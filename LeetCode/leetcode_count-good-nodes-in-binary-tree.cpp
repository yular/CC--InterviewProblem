/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n)
*/

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
    int goodNodes(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        
        int ans = 0, maxVal = INT_MIN;
        dfs(root, maxVal, ans);
        return ans;
    }
private:
    void dfs(TreeNode* root, int maxVal, int &ans) {
        if(root->val >= maxVal) {
            ++ ans;
        }
        
        maxVal = max(maxVal, root->val);
        if(root->left) {
            dfs(root->left, maxVal, ans);
        }
        if(root->right) {
            dfs(root->right, maxVal, ans);
        }
        return ;
    }
};
