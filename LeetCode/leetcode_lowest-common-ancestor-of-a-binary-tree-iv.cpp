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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* ans;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        if(nodes.size() == 0 || root == NULL) {
            return NULL;
        }
        if(nodes.size() == 1) {
            return nodes[0];
        }
        
        unordered_set<int> dict;
        for(TreeNode* nd : nodes) {
            dict.insert(nd->val);
        }
        
        int ndCnt = 0;
        unordered_map<int,int> ndDict;
        bool isFound = false;
        ans = NULL;
        dfs(root, ndCnt, dict, ndDict, isFound);
        
        return ans;
    }
    
private:
    void dfs(TreeNode* root, int &ndCnt, unordered_set<int> &dict, unordered_map<int,int> &ndDict, bool &isFound) {
        int lCnt = 0, rCnt = 0;
        if(root->left != NULL) {
            dfs(root->left, lCnt, dict, ndDict, isFound);
        }
        if(isFound) {
            return ;
        }
        
        if(root->right != NULL) {
            dfs(root->right, rCnt, dict, ndDict, isFound);
        }
        if(isFound) {
            return ;
        }
        
        if(dict.count(root->val)) {
            ndDict[root->val] = 1;
        }
        ndDict[root->val] += lCnt + rCnt;
        if(ndDict[root->val] == (int)dict.size()) {
            isFound = true;
            ans = root;
        }
        ndCnt = ndDict[root->val];
        return ;
    }
};
