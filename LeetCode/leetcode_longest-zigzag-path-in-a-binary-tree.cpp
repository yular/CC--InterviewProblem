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
    int longestZigZag(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        
        int ans = 0;
        unordered_map<TreeNode*, pair<int,int>> dict;
        fillInLogestPath(root, ans, dict);
        return ans;
    }
    
private:
    void fillInLogestPath(TreeNode* root, int &ans, unordered_map<TreeNode*, pair<int,int>> &dict) {
        dict[root] = make_pair(0, 0);
        if(root->left == NULL && root->right == NULL) {
            return;
        }
        
        if(root->left) {
            fillInLogestPath(root->left, ans, dict);
            dict[root].first = dict[root->left].second + 1;
            ans = max(ans, dict[root].first);
        }
        if(root->right) {
            fillInLogestPath(root->right, ans, dict);
            dict[root].second = dict[root->right].first + 1;
            ans = max(ans, dict[root->right].first + 1);
        }
        return ;
    }
};
