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
    bool isEvenOddTree(TreeNode* root) {
        if(root == NULL) {
            return true;
        }
        
        queue<TreeNode *> q;
        q.push(root);
        int levelIdx = 0;
        while(!q.empty()) {
            queue<TreeNode *> nxtQ;
            vector<int> vals(q.size());
            int idx = 0;
            while(!q.empty()) {
                TreeNode *cur = q.front();
                q.pop();
                
                vals[idx ++] = cur->val;
                if(cur->left) {
                    nxtQ.push(cur->left);
                }
                if(cur->right) {
                    nxtQ.push(cur->right);
                }
            }
            
            for(int i = 0; i < vals.size(); ++ i) {
                if( (levelIdx%2 == 0 && vals[i]%2 == 0 ) || (levelIdx%2 == 1 && vals[i]%2 == 1 ) ) {
                    return false;
                }
                if( i > 0 && ( (levelIdx%2 == 0 && vals[i] <= vals[i - 1] ) || (levelIdx%2 == 1 && vals[i] >= vals[i - 1]) ) ) {
                    return false;
                }
            }
            
            q = nxtQ;
            ++ levelIdx;
        }
        return true;
    }
};
