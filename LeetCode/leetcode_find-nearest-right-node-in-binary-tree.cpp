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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        if(root == NULL || u == NULL || u == root) {
            return NULL;
        }
        
        queue<TreeNode *> curQ;
        curQ.push(root);
        while(!curQ.empty()) {
            queue<TreeNode *> nxtQ;
            while(!curQ.empty()) {
                TreeNode *cur = curQ.front();
                curQ.pop();
                if(cur == u) {
                    return curQ.empty()? NULL : curQ.front();
                }
                
                if(cur->left) {
                    nxtQ.push(cur->left);
                }
                if(cur->right) {
                    nxtQ.push(cur->right);
                }
            }
            
            curQ = nxtQ;
        }
        return NULL;
    }
};
