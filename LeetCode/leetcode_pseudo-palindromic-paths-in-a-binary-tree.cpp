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
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        
        vector<int> cnt(10, 0);
        int ans = 0;
        dfs(root, cnt, ans);
        return ans;
    }
private:
    void dfs(TreeNode* root, vector<int> &cnt, int &ans) {
        ++ cnt[root->val];
        if(root->left == NULL && root->right == NULL) {
            if(canFindPalidrome(cnt)) {
                ++ ans;
            }
        }
        
        if(root->left) {
            dfs(root->left, cnt, ans);
        }
        if(root->right) {
            dfs(root->right, cnt, ans);
        }
        
        -- cnt[root->val];
        return ;
    }
    
    bool canFindPalidrome(vector<int> &cnt) {
        int numOfOdd = 0;
        for(int i = 0; i < cnt.size(); ++ i) {
            numOfOdd += (cnt[i]%2);
        }
        return numOfOdd < 2;
    }
};
