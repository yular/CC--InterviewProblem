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
    bool checkEqualTree(TreeNode* root) {
        if(root == NULL) {
            return true;
        }
        
        int tot = 0;
        int sum = getTreeSum(root, tot);
        if((sum&1) > 0) {
            return false;
        }
        
        bool canFindPartition = false;
        int curSum = 0, cnt = 0;
        dfs(root, sum/2, curSum, tot, cnt, canFindPartition);
        return canFindPartition;
    }
private:
    int getTreeSum(TreeNode* root, int &tot) {
        if(root == NULL) {
            return 0;
        }
        
        int sum = root->val;
        sum += getTreeSum(root->left, tot);
        sum += getTreeSum(root->right, tot);
        ++ tot;
        return sum;
    }
    
    void dfs(TreeNode* root, int target, int &sum, int tot, int &cnt, bool &canFindPartition) {
        if(root == NULL) {
            return ;
        }
        
        int curSum = 0;
        dfs(root->left, target, curSum, tot, cnt, canFindPartition);
        if(canFindPartition) {
            return ;
        }
        
        sum += curSum;
        curSum = 0;
        dfs(root->right, target, curSum, tot, cnt, canFindPartition);
        if(canFindPartition) {
            return ;
        }
        
        sum += curSum + root->val;
        ++ cnt;
        if(sum == target && cnt < tot) {
            canFindPartition = true;
        }
        return ;
    }
};
