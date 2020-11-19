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
    TreeNode *badNode;
public:
    TreeNode* correctBinaryTree(TreeNode* root) {
        if(root == NULL) {
            return root;
        }
        
        unordered_map<TreeNode *, TreeNode *> rightChildDict;
        badNode = root;
        findInvalidNode(root, rightChildDict);
        
        stack<TreeNode *> stk;
        stk.push(root);
        while(!stk.empty()) {
            TreeNode *cur = stk.top();
            stk.pop();
            
            if(cur->left == badNode) {
                cur->left = NULL;
                break;
            }
            if(cur->right == badNode) {
                cur->right = NULL;
                break;
            }
            
            if(cur->left) {
                stk.push(cur->left);
            }
            if(cur->right) {
                stk.push(cur->right);
            }
        }
        return root;
    }
private:
    void findInvalidNode(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &rightChildDict) {
        if(root->left != NULL) {
            if(rightChildDict.count(root->left) != 0) {
                badNode = rightChildDict[root->left];
                return ;
            }
            findInvalidNode(root->left, rightChildDict);
        }
        
        if(root->right != NULL) {
            if(rightChildDict.count(root->right) != 0) {
                badNode = rightChildDict[root->right];
                return ;
            }
            rightChildDict[root->right] = root;
            findInvalidNode(root->right, rightChildDict);
        }
        return ;
    }
};
