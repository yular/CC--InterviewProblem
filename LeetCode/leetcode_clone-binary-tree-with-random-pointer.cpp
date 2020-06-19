/*
*
* Tag: DFS + Hash
* Time: O(n)
* Space: O(n)
*/

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
        if(root == NULL) {
            return NULL;
        }
        
        unordered_map<Node*, NodeCopy*> dic;
        dfs(root, dic);
        
        return dic[root];
    }
private:
    void dfs(Node* root, unordered_map<Node*, NodeCopy*> &dic) {
        if(dic.count(root) != 0) {
            return;
        }
        
        NodeCopy *node = new NodeCopy(root->val);
        dic[root] = node;
        
        if(root->random != NULL) {
            dfs(root->random, dic);
            dic[root]->random = dic[root->random];
        }
        
        if(root->left) {
            dfs(root->left, dic);
            dic[root]->left = dic[root->left];
        }
        
        if(root->right) {
            dfs(root->right, dic);
            dic[root]->right = dic[root->right];
        }
        return ;
    }
};
