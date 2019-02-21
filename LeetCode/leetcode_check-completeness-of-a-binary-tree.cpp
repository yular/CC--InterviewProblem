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
    bool isCompleteTree(TreeNode* root) {
        if(root == NULL) {
            return true;
        }
        
        int numOfLayers = 0;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()) {
            queue<TreeNode *> nextQ;
            int numOfNodes = 0;
            bool isLastLayer = true, hasFoundNull = false;
            while(!q.empty()) {
                TreeNode *cur = q.front();
                q.pop();
                if(cur == NULL) {
                    hasFoundNull = true;
                    continue;
                }
                if(hasFoundNull) {
                    return false;
                }
                
                if(cur->left == NULL && cur->right != NULL) {
                    return false;
                }
                if(cur->left != NULL || cur->right != NULL) {
                    isLastLayer = false;
                }
                
                nextQ.push(cur->left);
                nextQ.push(cur->right);
                ++ numOfNodes;
            }
            
            if(!isLastLayer && numOfNodes != (1<<numOfLayers)) {
                return false;
            }
            q = nextQ;
            ++ numOfLayers;
        }
        
        return true;
    }
};
