/*
*
* Tag: DFS + BFS
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> ans;
        if(root == NULL || target == NULL){
            return ans;
        }
        
        stack<TreeNode *> stk;
        if(!canfindTarget(root, target, stk)){
            return ans;
        }
        
        int initDist = 0;
        unordered_set<TreeNode *> vis;
        while(!stk.empty()){
            TreeNode *cur = stk.top();
            stk.pop();
            
            queue<TreeNode *> q;
            q.push(cur);
            int dep = initDist;
            while(!q.empty() && dep <= K){
                queue<TreeNode *> nextQ;
                while(!q.empty()){
                    TreeNode *nxt = q.front();
                    q.pop();
                    
                    vis.insert(nxt);
                    if(dep == K){
                        ans.push_back(nxt->val);
                        continue;
                    }
                    
                    if(nxt->left != NULL && vis.count(nxt->left) == 0){
                        nextQ.push(nxt->left);
                    }
                    if(nxt->right != NULL && vis.count(nxt->right) == 0){
                        nextQ.push(nxt->right);
                    }
                }
                q = nextQ;
                ++ dep;
            }
            ++ initDist;
        }
        return ans;
    }
private:
    bool canfindTarget(TreeNode* root, TreeNode* target, stack<TreeNode *> &stk){
        stk.push(root);
        if(stk.top() == target){
            return true;
        }
        
        if(root->left != NULL && canfindTarget(root->left, target, stk)){
            return true;
        }
        if(root->right != NULL && canfindTarget(root->right, target, stk)){
            return true;
        }
        
        stk.pop();
        return false;
    }
};
