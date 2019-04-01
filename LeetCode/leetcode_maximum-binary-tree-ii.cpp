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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode *node = new TreeNode(val);
        if(root == NULL) {
            return node;
        }
        
        TreeNode dumy(-1);
        TreeNode *parent = &dumy;
        parent->right = root;
        while(root != NULL) {
            if(val > root->val) {
                node->left = root;
                parent->right = node;
                break;
            } else if(root->right == NULL) {
                root->right = node;
                break;
            }
            
            parent = root;
            root = root->right;
        }
        return dumy.right;
    }
};
