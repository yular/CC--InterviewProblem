/*
*
* Tag: DFS, HashMap
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
    const int MOD = 1e9 + 7;
public:
    int maxProduct(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        
        unordered_map<TreeNode*, int> nodeSum;
        int sum = 0;
        calNodeSum(root, nodeSum, sum);
        
        long long ans = 0;
        getMaxProduct(root, nodeSum, sum, ans);
        return ans%MOD;
    }
private:
    void calNodeSum(TreeNode* root, unordered_map<TreeNode*, int> &nodeSum, int &sum) {
        int leftSum = 0;
        if(root->left) {
            calNodeSum(root->left, nodeSum, leftSum);
        }
        
        int rightSum = 0;
        if(root->right) {
            calNodeSum(root->right, nodeSum, rightSum);
        }
        
        sum = leftSum + rightSum + root->val;
        nodeSum[root] = sum;
        return ;
    }
    
    void getMaxProduct(TreeNode* root, unordered_map<TreeNode*, int> &nodeSum, int &sum, long long &ans) {
        if(root->left) {
            long long resSum = sum - nodeSum[root->left];
            long long product = resSum*nodeSum[root->left];
            ans = max(ans, product);
            
            getMaxProduct(root->left, nodeSum, sum, ans);
        }
        
        if(root->right) {
            long long resSum = sum - nodeSum[root->right];
            long long product = resSum*nodeSum[root->right];
            ans = max(ans, product);
            
            getMaxProduct(root->right, nodeSum, sum, ans);
        }
        
        return ;
    }
};
