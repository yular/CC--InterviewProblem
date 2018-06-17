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
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        vector<TreeNode*> ans(2, NULL);
        if(root == NULL){
            return ans;
        }
        
        TreeNode *parentOfRoot = new TreeNode(-1);
        parentOfRoot->left = root;
        
        TreeNode* nodeOfSplitedBST = findRootNodeOfSplitedBST(parentOfRoot, V);
        ans[0] = nodeOfSplitedBST;
        ans[1] = parentOfRoot->left;
        
        return ans;
    }
    
private:
    TreeNode* findRootNodeOfSplitedBST(TreeNode *root, int V) {
        if(root == NULL || (root->left == NULL && root->right == NULL) ) {
            return NULL;
        }
        
        if(root->left != NULL) {
            TreeNode *leftChild = root->left;
            if(leftChild->val <= V) {
                TreeNode *newLeftNodeOfRoot = findParentNodeOfAddedBST(leftChild, V);
                
                root->left = newLeftNodeOfRoot == NULL ? NULL : newLeftNodeOfRoot->right;
                
                if(newLeftNodeOfRoot != NULL) {
                    newLeftNodeOfRoot->right = findRootNodeOfSplitedBST(newLeftNodeOfRoot->right, V);
                }
                
                return leftChild;
            }
            return findRootNodeOfSplitedBST(leftChild, V);
        }
        
        return NULL;
    }
    
    TreeNode* findParentNodeOfAddedBST(TreeNode *root, int V){
        if(root == NULL || (root->left == NULL && root->right == NULL) ) {
            return NULL;
        }
        
        while(root->right != NULL) {
            TreeNode *rightChild = root->right;
            if(rightChild->val > V) {
                return root;
            }
            root = rightChild;
        }
        
        return NULL;
    }
};
