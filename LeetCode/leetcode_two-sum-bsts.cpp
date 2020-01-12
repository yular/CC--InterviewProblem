/*
*
* Tag: DFS+BFS
* Time:O(n)
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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        if(root1 == NULL || root2 == NULL) {
            return false;
        }
        
        unordered_set<int> values;
        readBST(root1, values);
        
        queue<TreeNode *> q;
        q.push(root2);
        while(!q.empty()) {
            TreeNode * cur = q.front();
            q.pop();
            int res = target - cur->val;
            if(values.count(res) != 0){
                return true;
            }
            if(cur->left) {
                q.push(cur->left);
            }
            if(cur->right){
                q.push(cur->right);
            }
        }
        return false;
    }
private:
    void readBST(TreeNode* root, unordered_set<int> &values){
        if(root == NULL) {
            return ;
        }
        values.insert(root->val);
        if(root->left != NULL){
            readBST(root->left, values);
        }
        if(root->right != NULL){
            readBST(root->right, values);
        }
    }
};
