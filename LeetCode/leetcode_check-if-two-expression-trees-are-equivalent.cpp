/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n)
*/

/**
 * Definition for a binary tree node.
 * struct Node {
 *     char val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(' '), left(nullptr), right(nullptr) {}
 *     Node(char x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool checkEquivalence(Node* root1, Node* root2) {
        if((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL)) {
            return false;
        }
        if(root1 == root2) {
            return true;
        }
        
        vector<int> varCnt(26, 0);
        dfs(root1, 1, varCnt);
        dfs(root2, -1, varCnt);
        
        bool isEqual = true;
        for(int i = 0; i < 26; ++ i) {
            if(varCnt[i] != 0) {
                isEqual = false;
                break;
            }
        }
        return isEqual;
    }
private:
    void dfs(Node* root, int v, vector<int> &varCnt) {
        if(root == NULL) {
            return ;
        }
        
        if(root->val != '+') {
            varCnt[root->val - 'a'] += v;
            if(varCnt[root->val - 'a'] < 0) {
                return ;
            }
        }
        
        if(root->left) {
            dfs(root->left, v, varCnt);
        }
        if(root->right) {
            dfs(root->right, v, varCnt);
        }
        return ;
    }
};
