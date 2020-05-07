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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        if(root1 == NULL && root2 == NULL){
            return ans;
        }
        
        stack<TreeNode *> stk1, stk2;
        addLeftChildChain(root1, stk1);
        addLeftChildChain(root2, stk2);
        
        TreeNode *stk1Node = NULL, *stk2Node = NULL;
        while(!stk1.empty() || !stk2.empty()){
            if(!stk1.empty() && !stk2.empty()) {
                stk1Node = stk1.top(), stk2Node = stk2.top();
                if(stk1Node->val <= stk2Node->val){
                    ans.push_back(stk1Node->val);
                    stk1.pop();
                    addLeftChildChain(stk1Node->right, stk1);
                } else {
                    ans.push_back(stk2Node->val);
                    stk2.pop();
                    addLeftChildChain(stk2Node->right, stk2);
                }
            } else if(!stk1.empty()){
                stk1Node = stk1.top();
                ans.push_back(stk1Node->val);
                stk1.pop();
                addLeftChildChain(stk1Node->right, stk1);
            } else {
                stk2Node = stk2.top();
                ans.push_back(stk2Node->val);
                stk2.pop();
                addLeftChildChain(stk2Node->right, stk2);
            }
        }
        return ans;
    }
private:
    void addLeftChildChain(TreeNode* root, stack<TreeNode *> &stk){
        while(root != NULL) {
            stk.push(root);
            root = root->left;
        }
        
        return;
    }
};
