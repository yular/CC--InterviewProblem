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
    Node* lowestCommonAncestor(Node* p, Node * q) {
        if(p == q || p == NULL || q == NULL) {
            return p;
        }
        
        Node *root = p;
        int h = 0;
        while(root->parent != NULL) {
            root = root->parent;
            ++ h;
        }
        
        unordered_map<Node *, int> nodeHeight;
        fillInHeight(nodeHeight, root, p, q, 0);
        if(nodeHeight.count(p) == 0 || nodeHeight.count(q) == 0) {
            return NULL;
        }
        
        while(nodeHeight[p] < nodeHeight[q]) {
            q = q->parent;
        }
        
        while(nodeHeight[q] < nodeHeight[p]) {
            p = p->parent;
        }
        if(p == q) {
            return p;
        }
        
        while(p->parent != q->parent) {
            p = p->parent;
            q = q->parent;
        }
        return p->parent;
    }
private:
    void fillInHeight(unordered_map<Node *, int> &nodeHeight, Node* root, Node* p, Node* q, int h) {
        nodeHeight[root] = h;
        if(nodeHeight.count(p) > 0 && nodeHeight.count(q) > 0) {
            return ;
        }
        
        if(root->left != NULL) {
            fillInHeight(nodeHeight, root->left, p, q, h + 1);
        }
        if(nodeHeight.count(p) > 0 && nodeHeight.count(q) > 0) {
            return ;
        }
        
        if(root->right != NULL) {
            fillInHeight(nodeHeight, root->right, p, q, h + 1);
        }
        return ;
    }
};
