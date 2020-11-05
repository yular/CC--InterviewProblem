/*
*
* Tag: DFS + Hash
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || p == NULL || q == NULL) {
            return NULL;
        }
        
        unordered_map<TreeNode *, TreeNode *> parentDict;
        unordered_map<TreeNode *, int> height;
        
        fillDict(parentDict, height, p, q, root, NULL, 0);
        if(parentDict.count(p) == 0 || parentDict.count(q) == 0) {
            return NULL;
        }
        
        int minH = min(height[p], height[q]);
        while(p != NULL && height[p] > minH) {
            p = parentDict[p];
        }
        while(q != NULL && height[q] > minH) {
            q = parentDict[q];
        }
        if(p == q) {
            return p;
        }
        
        while(p != NULL && parentDict[p] != parentDict[q]) {
            p = parentDict[p];
            q = parentDict[q];
        }
        return parentDict[p];
    }
private:
    void fillDict(unordered_map<TreeNode *, TreeNode *> &parentDict, unordered_map<TreeNode *, int> &height, TreeNode* p, TreeNode* q, TreeNode *root, TreeNode *parent, int h) {
        parentDict[root] = parent;
        height[root] = h;
        if(parentDict.count(p) > 0 && parentDict.count(q) > 0) {
            return ;
        }
        
        if(root->left) {
            fillDict(parentDict, height, p, q, root->left, root, h + 1);
        }
        if(root->right) {
            fillDict(parentDict, height, p, q, root->right, root, h + 1);
        }
        return ;
    }
};
