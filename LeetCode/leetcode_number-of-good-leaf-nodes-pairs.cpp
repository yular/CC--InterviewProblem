/*
*
* Tag: DFS
* Time: O(n^2)
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
    int countPairs(TreeNode* root, int distance) {
        if(root == NULL || distance < 1) {
            return 0;
        }
        
        int ans = 0;
        dfs(root, distance, ans);
        return ans;
    }
private:
    vector<int> dfs(TreeNode* root, int d, int &ans) {
        vector<int> child;
        if(root->left == NULL && root->right == NULL) {
            child.push_back(1);
            return child;
        }
        
        vector<int> lchild, rchild;
        if(root->left) {
            lchild = dfs(root->left, d, ans);
        }
        if(root->right) {
            rchild = dfs(root->right, d, ans);
        }
        
        for(int i = 0; i < lchild.size(); ++ i) {
            for(int j = 0; j < rchild.size(); ++ j) {
                if(lchild[i] + rchild[j] <= d) {
                    ++ ans;
                }
            }
        }
        
        for(int i = 0; i < lchild.size(); ++ i) {
            child.push_back(lchild[i] + 1);
        }
        for(int i = 0; i < rchild.size(); ++ i) {
            child.push_back(rchild[i] + 1);
        }
        return child;
    }
};
