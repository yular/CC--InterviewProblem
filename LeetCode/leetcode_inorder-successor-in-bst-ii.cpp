/*
*
* Tag: DFS
* Time: O(n)
* Space: O(1)
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
    Node* inorderSuccessor(Node* node) {
        if(node == NULL){
            return node;
        }
        
        if(node->right != NULL){
            node = node->right;
            while(node->left != NULL) {
                node = node->left;
            }
            return node;
        }
        
        while(node->parent != NULL && node->parent->val < node->val) {
            node = node->parent;
        }
        return node->parent;
    }
};
