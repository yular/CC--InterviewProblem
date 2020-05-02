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
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        if(root == NULL) {
            return false;
        }
        
        bool isValid = false;
        dfs(root, arr, 0, isValid);
        return isValid;
    }
private:
    void dfs(TreeNode* root, vector<int>& arr, int idx, bool &isValid) {
        if(idx >= arr.size() || root->val != arr[idx]) {
            return ;
        }
        
        if(root->left == NULL && root->right == NULL && idx + 1 >= arr.size()) {
            isValid = true;
            return ;
        }
        
        if(root->left) {
            dfs(root->left, arr, idx + 1, isValid);
        }
        if(isValid) {
            return ;
        }
        
        if(root->right) {
            dfs(root->right, arr, idx + 1, isValid);
        }
        return ;
    }
};
