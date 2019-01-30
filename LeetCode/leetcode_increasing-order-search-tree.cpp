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
private:
    TreeNode *p;
public:
    TreeNode* increasingBST(TreeNode* root) {
        if(root == NULL){
            return root;
        }
        
        TreeNode dump(-1);
        p = &dump;
        buildTreeNodesChain(root);
        return dump.right;
    }
private:
    void buildTreeNodesChain(TreeNode* root){
        if(root == NULL){
            return;
        }
        
        buildTreeNodesChain(root->left);
        root->left = NULL;
        p->right = root;
        p = root;
        buildTreeNodesChain(root->right);
    }
};
