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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original == NULL || cloned == NULL || target == NULL) {
            return NULL;
        }
        
        queue<TreeNode *> origQueue, cloneQueue;
        origQueue.push(original);
        cloneQueue.push(cloned);
        while(!origQueue.empty() && !cloneQueue.empty()) {
            TreeNode *origCur = origQueue.front(), *cloneCur = cloneQueue.front();
            origQueue.pop();
            cloneQueue.pop();
            if(origCur == target) {
                return cloneCur;
            }
            
            if(origCur->left) {
                origQueue.push(origCur->left);
                cloneQueue.push(cloneCur->left);
            }
            if(origCur->right) {
                origQueue.push(origCur->right);
                cloneQueue.push(cloneCur->right);
            }
        }
        return NULL;
    }
};
