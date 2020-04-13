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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL) {
            return true;
        }
        
        if( (root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL) ) {
            return false;
        }
        
        if(root1->val != root2->val){
            return false;
        }
        
        if(flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) {
            return true;
        }
        
        swap(root1->left, root1->right);
        return flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
    }
};
