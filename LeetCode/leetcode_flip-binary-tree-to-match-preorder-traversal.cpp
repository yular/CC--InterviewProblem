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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        if(root == NULL && voyage.size() == 0) {
            return {};
        }
        if(root == NULL && voyage.size() > 0) {
            return {-1};
        }
        
        vector<int> ans;
        bool isValid = true;
        int idx = 0;
        dfs(root, voyage, idx, ans, isValid);
        if(!isValid) {
            return {-1};
        }
        
        return ans;
    }
private:
    void dfs(TreeNode* root, vector<int>& arr, int &idx, vector<int> &ans, bool &isValid) {
        if(root == NULL || root->val != arr[idx]) {
            isValid = false;
            return ;
        }
        
        ++ idx;
        if(root->left == NULL && root->right == NULL) {
            return ;
        }
        
        int curIdx = idx;
        bool curValid = true;
        if(root->left) {
            dfs(root->left, arr, idx, ans, curValid);
        }
        if(curValid) {
            curValid = true;
            if(root->right) {
                dfs(root->right, arr, idx, ans, curValid);
            }
            if(curValid) {
                return ;
            }
        }
        
        curValid = true;
        swap(root->left, root->right);
        idx = curIdx;
        if(root->left) {
            dfs(root->left, arr, idx, ans, curValid);
        }
        if(curValid == false) {
            isValid = false;
            return ;
        }
        
        if(root->right) {
            dfs(root->right, arr, idx, ans, curValid);
        }
        if(curValid) {
            ans.push_back(root->val);
            return ;
        }
        isValid = curValid;
        return ;
    }
};
