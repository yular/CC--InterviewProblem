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
    vector<int> getLonelyNodes(TreeNode* root) {
        if(root == NULL) {
            return {};
        }
        
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
private:
    void dfs(TreeNode *root, vector<int> &ans) {
        if(root->left) {
            if(root->right == NULL) {
                ans.push_back(root->left->val);
            }
            
            dfs(root->left, ans);
        }
        
        if(root->right) {
            if(root->left == NULL) {
                ans.push_back(root->right->val);
            }
            
            dfs(root->right, ans);
        }
        return ;
    }
};
