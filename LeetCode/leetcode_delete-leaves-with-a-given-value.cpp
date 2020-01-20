/*
*
* Tag: DFS
* Time: O(n)
* Space: O(1)
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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root == NULL){
            return root;
        }
        
        removeLeaves(&root, target);
        return root;
    }
private:
    void removeLeaves(TreeNode** root, int target) {
        if((*root)->left != NULL) {
            removeLeaves(&((*root)->left), target);
        }
        if((*root)->right != NULL) {
            removeLeaves(&((*root)->right), target);
        }
        
        if((*root)->left == NULL && (*root)->right == NULL && (*root)->val == target) {
            *root = NULL;
        }
        return ;
    }
};
