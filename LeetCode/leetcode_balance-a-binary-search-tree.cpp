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
    TreeNode* balanceBST(TreeNode* root) {
        if(root == NULL) {
            return root;
        }
        
        vector<int> values;
        dfs(root, values);
        //cout<<values.size()<<endl;
        
        TreeNode *newRoot;
        buildTree(&newRoot, values, 0, values.size() - 1);
        return newRoot;
    }
private:
    void dfs(TreeNode* root, vector<int> &values) {
        if(root->left) {
            dfs(root->left, values);
        }
        values.push_back(root->val);
        
        if(root->right) {
            dfs(root->right, values);
        }
        return ;
    }
    
    void buildTree(TreeNode **root, vector<int> &values, int l, int r) {
        if(l > r) {
            return;
        }
        
        int mid = (l + r)/2;
        *root = new TreeNode(values[mid]);
        if(l == r) {
            return ;
        }
        
        buildTree(&((*root)->left), values, l, mid - 1);
        buildTree(&((*root)->right), values, mid + 1, r);
        return ;
    }
};
