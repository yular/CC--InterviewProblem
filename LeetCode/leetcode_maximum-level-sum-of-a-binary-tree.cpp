/*
*
* Tag: BFS 
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
    int maxLevelSum(TreeNode* root) {
        if(root == NULL) {
            return -1;
        }
        
        long long maxSum = root->val, ans = 1, lv = 1;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            queue<TreeNode *> nextQ;
            long long sum = 0;
            while(!q.empty()) {
                TreeNode * cur = q.front();
                q.pop();
                sum += cur->val;
                if(cur->left) {
                    nextQ.push(cur->left);
                }
                if(cur->right) {
                    nextQ.push(cur->right);
                }
            }
            if(sum > maxSum) {
                maxSum = sum;
                ans = lv;
            }
            ++ lv;
            q = nextQ;
        }
        return ans;
    }
};
