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
class BSTIterator {
private:
    vector<int> valList;
    int idx;
public:
    BSTIterator(TreeNode* root) {
        fillValList(root);
        idx = -1;
    }
    
    bool hasNext() {
        if(idx >= ((int)valList.size() - 1)) {
            return false;
        }
        return true;
    }
    
    int next() {
        return valList[++ idx];
    }
    
    bool hasPrev() {
        if(idx < 1) {
            return false;
        }
        return true;
    }
    
    int prev() {
        return valList[-- idx];
    }
private:
    void fillValList(TreeNode* root) {
        if(root == NULL) {
            return ;
        }
        
        if(root->left) {
            fillValList(root->left);
        }
        
        valList.push_back(root->val);
        
        if(root->right) {
            fillValList(root->right);
        }
        return ;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * bool param_1 = obj->hasNext();
 * int param_2 = obj->next();
 * bool param_3 = obj->hasPrev();
 * int param_4 = obj->prev();
 */
 
 
