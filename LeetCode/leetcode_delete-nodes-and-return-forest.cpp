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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode *> ans;
        if(root == NULL) {
            return ans;
        }
        if(to_delete.size() == 0) {
            ans.push_back(root);
            return ans;
        }
        
        unordered_set<int> deleteNodes(to_delete.begin(), to_delete.end());
        unordered_map<int,TreeNode *> forest;
        forest[root->val] = root;
        
        queue<TreeNode **> q;
        q.push(&root);
        while(!q.empty()) {
            TreeNode **cur = q.front();
            q.pop();
            if((*cur)->left != NULL) {
                q.push(&((*cur)->left));
            }
            if((*cur)->right != NULL) {
                q.push(&((*cur)->right));
            }
            if(deleteNodes.count((*cur)->val) == 0){
                continue;
            }

            forest.erase((*cur)->val);
            if((*cur)->left != NULL) {
                forest[(*cur)->left->val] = (*cur)->left;
            }
            if((*cur)->right != NULL) {
                forest[(*cur)->right->val] = (*cur)->right;
            }
            *cur = NULL;
        }
        
        for(auto it = forest.begin(); it != forest.end(); it ++) {
            ans.push_back(it->second);
        }
        return ans;
    }
};
