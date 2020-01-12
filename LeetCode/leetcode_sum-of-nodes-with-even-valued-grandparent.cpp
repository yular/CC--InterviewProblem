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
    int sumEvenGrandparent(TreeNode* root) {
        int ans = 0;
        if(root == NULL) {
            return ans;
        }
        calculateSum(root, NULL, ans);
        return ans;
    }
private:
    void calculateSum(TreeNode* root, TreeNode* parent, int &ans){
        if(root->left) {
            if(parent != NULL && (parent->val&1) == 0){
                ans += root->left->val;
            }
            calculateSum(root->left, root, ans);
        }
        if(root->right) {
            if(parent != NULL && (parent->val&1) == 0){
                ans += root->right->val;
            }
            calculateSum(root->right, root, ans);
        }
    }
};
