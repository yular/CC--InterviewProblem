/*
*
* Tag: 
* Time: O(n^2)
* Space: O(n)
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    bool isSubPath(ListNode* head, TreeNode* root) {
        if((head == NULL && root != NULL) || (head != NULL && root == NULL) ) {
            return false;
        }
        
        return canFindSubPath(head, root);
    }
private:
    bool canFindSubPath(ListNode* head, TreeNode* root) {
        if(head->val == root->val){
            if(dfs(head, root)){
                return true;
            }
        }
        
        if(root->left && canFindSubPath(head, root->left)) {
            return true;
        }
        
        if(root->right && canFindSubPath(head, root->right)) {
            return true;
        }
        return false;
    }
    
    bool dfs(ListNode* head, TreeNode* root) {
        if(head == NULL || root == NULL) {
            return false;
        }
        if(head->val != root->val) {
            return false;
        }
        
        if(head->next == NULL) {
            return true;
        }
        
        if(root->left != NULL && dfs(head->next, root->left)) {
            return true;
        }
        
        if(root->right != NULL && dfs(head->next, root->right)) {
            return true;
        }
        
        return false;
    }
};
