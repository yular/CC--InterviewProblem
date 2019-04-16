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
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        if(root == NULL) {
            return ans;
        }
        
        int maxChild = INT_MIN, minChild = INT_MAX;
        findMaxDiff(root, ans, maxChild, minChild);
        return ans;
    }
private:
    void findMaxDiff(TreeNode* root, int &ans, int &maxChild, int &minChild){
        maxChild = max(maxChild, root->val);
        minChild = min(minChild, root->val);
        if(root->right == NULL && root->left == NULL){
            return ;
        }
        
        if(root->left != NULL){
            int nxtMaxChild = INT_MIN, nxtMinChild = INT_MAX;
            findMaxDiff(root->left, ans, nxtMaxChild, nxtMinChild);
            maxChild = max(maxChild, nxtMaxChild);
            minChild = min(minChild, nxtMinChild);
        }
        if(root->right != NULL) {
            int nxtMaxChild = INT_MIN, nxtMinChild = INT_MAX;
            findMaxDiff(root->right, ans, nxtMaxChild, nxtMinChild);
            maxChild = max(maxChild, nxtMaxChild);
            minChild = min(minChild, nxtMinChild);
        }
        ans = max(ans, abs(root->val - maxChild));
        ans = max(ans, abs(root->val - minChild));
    }
};
