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
    double maximumAverageSubtree(TreeNode* root) {
        double ans = 0;
        if(root == NULL) {
            return ans;
        }
        
        long long sum = 0; 
        int numOfNodes = 0;
        dfs(root, sum, numOfNodes, ans);
        return ans;
    }
    
private:
    void dfs(TreeNode* root, long long &sum, int &numOfNodes, double &ans){
        if(root == NULL){
            return ;
        }
        
        long long LeftSum = 0; 
        int numOfLeftNodes = 0;
        if(root->left) {
            dfs(root->left, LeftSum, numOfLeftNodes, ans);
        }
        
        long long RightSum = 0;
        int numOfRightNodes = 0;
        if(root->right) {
            dfs(root->right, RightSum, numOfRightNodes, ans);
        }
        
        numOfNodes = (numOfLeftNodes + numOfRightNodes + 1);
        sum = (LeftSum + RightSum + root->val);
        ans = max(ans, sum/(numOfNodes*1.0));
    }
};
