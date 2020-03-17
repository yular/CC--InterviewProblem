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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        
        int sum = 0, val = 0;
        dfs(root, sum, val);
        return sum;
    }
private:
    void dfs(TreeNode* root, int &sum, int &val) {
        int cur = (val<<1) | (root->val);
        if(root->left == NULL && root->right == NULL) {
            sum += cur;
            return ;
        }
        
        if(root->left) {
            dfs(root->left, sum, cur);
        }
        if(root->right) {
            dfs(root->right, sum, cur);
        }
        return ;
    }
};
