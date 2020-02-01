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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root == NULL){
            return root;
        }
        
        unordered_map<TreeNode*, TreeNode*> parent;
        parent[root] = NULL;
        unordered_set<TreeNode*> depLeaves;
        int maxDep = 0;
        
        fillInDeepestLeaves(root, 0, maxDep, parent, depLeaves);
        
        unordered_set<TreeNode*> nxtLevel;
        while(depLeaves.size() > 1){
            for(auto it = depLeaves.begin(); it != depLeaves.end(); ++ it) {
                nxtLevel.insert(parent[*it]);
            }
            depLeaves = nxtLevel;
            nxtLevel.clear();
        }
        return *(depLeaves.begin());
    }
    
private:
    void fillInDeepestLeaves(TreeNode* root, int dep, int &maxDep, unordered_map<TreeNode*, TreeNode*> &parent, unordered_set<TreeNode*> &depLeaves) {
        if(root->left == NULL && root->right == NULL){
            if(maxDep < dep) {
                maxDep = dep;
                depLeaves.clear();
            }
            if(maxDep == dep) {
                depLeaves.insert(root);
            }
            return ;
        }
        
        if(root->left != NULL) {
            parent[root->left] = root;
            fillInDeepestLeaves(root->left, dep + 1, maxDep, parent, depLeaves);
        }
        if(root->right != NULL) {
            parent[root->right] = root;
            fillInDeepestLeaves(root->right, dep + 1, maxDep, parent, depLeaves);
        }
        
        return ;
    }
};
