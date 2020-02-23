/*
*
* Tag: DFS + HashMap
* Time: O(n) for init, O(1) for query
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
class FindElements {
private:
    unordered_set<int> values;
public:
    FindElements(TreeNode* root) {
        fillNodeValues(root, 0);
    }
    
    bool find(int target) {
        return values.count(target) > 0;
    }
private:
    void fillNodeValues(TreeNode* root, int val) {
        values.insert(val);
        if(root->left != NULL) {
            fillNodeValues(root->left, 2*val + 1);
        }
        if(root->right != NULL) {
            fillNodeValues(root->right, 2*val + 2);
        }
        return ;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
