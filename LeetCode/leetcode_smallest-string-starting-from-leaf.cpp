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
    string smallestFromLeaf(TreeNode* root) {
        string ans = "", cur = "";
        if(root == NULL) {
            return ans;
        }
        
        dfs(root, cur, ans);
        return ans;
    }
    
private:
    void dfs(TreeNode* root, string cur, string &ans){
        cur += (char)(root->val + 'a');
        if(root->left == NULL && root->right == NULL){
            if(isSmaller(cur, ans)) {
                ans = cur;
            }
            return;
        }
        
        if(root->left != NULL) {
            dfs(root->left, cur, ans);
        }
        if(root->right != NULL) {
            dfs(root->right, cur, ans);
        } 
    }
private:
    bool isSmaller(string &cur, string &ans){
        reverse(cur.begin(), cur.end());
        if(ans == "") {
            return true;
        }
        
        for(int i = 0, j = 0; i < ans.size() && j < cur.size(); ++ i, ++ j) {
            if(ans[i] != cur[j]) {
                return cur[j] < ans[i];
            }
        }
        return cur.size() == ans.size() ? false : cur.size() < ans.size();
    }
};
