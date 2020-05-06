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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if(root == NULL) {
            return root;
        }
        
        long long sum = 0;
        dfs(&root, sum, limit);
        return root;
    }
private:
    void dfs(TreeNode** root, long long &sum, int limit) {
        sum += (*root)->val;
        int childCnt = 0, invaliChidCnt = 0;
        long long leftSum = sum, rightSum = sum, maxChildSum = LLONG_MIN;
        if((*root)->left != NULL) {
            ++ childCnt;
            dfs(&((*root)->left), leftSum, limit);
            if(leftSum < limit) {
                ++ invaliChidCnt;
            }
            maxChildSum = max(maxChildSum, leftSum);
        }
        
        if((*root)->right != NULL) {
            ++ childCnt;
            dfs(&((*root)->right), rightSum, limit);
            if(rightSum < limit) {
                ++ invaliChidCnt;
            }
            maxChildSum = max(maxChildSum, rightSum);
        }
        
        if((childCnt > 0 && invaliChidCnt == childCnt) || (childCnt == 0 && sum < limit)) {
            *root = NULL;
        }
        
        if(childCnt > 0) {
            sum = maxChildSum;
        }
        return ;
    }
};
