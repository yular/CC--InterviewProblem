/*
*
* Tag: DFS
* Time: O(n)
* Space: O(h)
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
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        updateTreeNodesValue(root, sum);
        return root;
    }
private:
    void updateTreeNodesValue(TreeNode* root, int &sum){
        if(root == NULL){
            return ;
        }
        updateTreeNodesValue(root->right, sum);
        sum += root->val;
        root->val = sum;
        updateTreeNodesValue(root->left, sum);
    }
};
