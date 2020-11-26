/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n)
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* flipBinaryTree(Node* root, Node * leaf) {
        if(root == NULL || leaf == NULL) {
            return NULL;
        }
        if(root == leaf) {
            return leaf;
        }
        
        stack<Node *> stk;
        dfs(root, leaf, stk);
        //cout<<stk.size()<<endl;
        
        bool isFirst = true;
        while(!stk.empty()) {
            Node *cur = stk.top();
            stk.pop();
            
            if(stk.empty()) {
                break;
            }
            if(isFirst) {
                cur->parent = NULL;
            }
            
            stk.top()->parent = cur;
            cur->left = stk.top();
            if(stk.top()->left == cur) {
                stk.top()->left = NULL;
            } else {
                if(stk.top() == root) {
                    stk.top()->right = NULL;
                } else {
                    stk.top()->right = stk.top()->left;
                    stk.top()->left = NULL;
                }
            }
            
            isFirst = false;
        }
        
        return leaf;
    }
private:
    void dfs(Node* root, Node * leaf, stack<Node *> &stk) {
        stk.push(root);
        if(root == leaf) {
            return ;
        }
        
        if(root->left) {
            dfs(root->left, leaf, stk);
        }
        if(!stk.empty() && stk.top() == leaf) {
            return ;
        }
        
        if(root->right) {
            dfs(root->right, leaf, stk);
        }
        if(!stk.empty() && stk.top() == leaf) {
            return ;
        }
        
        stk.pop();
        return ;
    }
};
