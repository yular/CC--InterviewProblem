/*
*
* Tag: Data Structure (Stack)
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
    TreeNode* recoverFromPreorder(string S) {
        if(S.size() == 0){
            return NULL;
        }
        
        stack<pair<TreeNode *, int>> stk;
        for(int i = 0; i < S.size(); ++ i){
            int numOfLevel = 0;
            while(i < S.size() && isdigit(S[i]) == false) {
                ++ i;
                ++ numOfLevel;
            }
            int val = -1;
            while(i < S.size() && isdigit(S[i])){
                if(val == -1){
                    val = 0;
                }
                val = val*10 + (S[i] - '0');
                ++ i;
            }
            if(val == -1){
                continue;
            }
            -- i;
            
            TreeNode* node = new TreeNode(val);
            while(!stk.empty()){
                pair<TreeNode*, int> parent = stk.top();
                if(parent.second == numOfLevel - 1) {
                    if(parent.first->left == NULL){
                        parent.first->left = node;
                    } else {
                        parent.first->right = node;
                    }
                    break;
                }
                stk.pop();
            }
            stk.push(make_pair(node, numOfLevel));
        }
        
        while(stk.size() > 1) {
            stk.pop();
        }
        return stk.top().first;
    }
};
