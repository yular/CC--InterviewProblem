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
    int deepestLeavesSum(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        
        int ans = 0, maxDep = 0;
        dfs(root, 1, maxDep, ans);
        return ans;
    }
private:
    void dfs(TreeNode* root, int dep, int &maxDep, int &ans){
        if(root->left == NULL && root->right == NULL && dep >= maxDep){
            if(dep > maxDep) {
                maxDep = dep;
                ans = 0;
            }
            ans += root->val;
            
            return ;
        }
        
        if(root->left){
            dfs(root->left, dep+1, maxDep, ans);
        }
        if(root->right){
            dfs(root->right, dep+1, maxDep, ans);
        }
        
        return;
    }
};
