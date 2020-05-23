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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        if(n < 3) {
            return false;
        }
        
        bool canWin = false;
        vector<int> treeSize(n + 1, 0);
        dfs(root, treeSize, canWin, n, x);
        
        return canWin;
    }
private:
    void dfs(TreeNode* root, vector<int> &treeSize, bool &canWin, int n, int x) {
        int cnt = 0;
        if(root->left) {
            dfs(root->left, treeSize, canWin, n, x);
            cnt += treeSize[root->left->val];
            if(root->val == x && treeSize[root->left->val]*2 > n) {
                canWin = true;
            }
        }
        if(canWin) {
            return ;
        }
        
        if(root->right) {
            dfs(root->right, treeSize, canWin, n, x);
            cnt += treeSize[root->right->val];
            if(root->val == x && treeSize[root->right->val]*2 > n) {
                canWin = true;
            }
        }
        if(canWin) {
            return ;
        }
        
        treeSize[root->val] = cnt + 1;
        if(root->val == x && treeSize[root->val]*2 < n) {
            canWin = true;
        }
        return;
    }
};
