/*
*
* Tag: BFS
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
class CBTInserter {
private:
    TreeNode* cbtroot;
    queue<TreeNode *> q;
public:
    CBTInserter(TreeNode* root) {
        cbtroot = root;
        queue<TreeNode *> tmpq;
        tmpq.push(root);
        while(!tmpq.empty()){
            TreeNode *cur = tmpq.front();
            tmpq.pop();
            q.push(cur);
            if(cur->left != NULL){
                tmpq.push(cur->left);
            }
            if(cur->right != NULL){
                tmpq.push(cur->right);
            }
        }
    }
    
    int insert(int v) {
        int ans = 0;
        while(!q.empty()){
            TreeNode *cur = q.front();
            if(cur->left == NULL){
                cur->left = new TreeNode(v);
                ans = cur->val;
                q.push(cur->left);
                break;
            } else if(cur->right == NULL){
                cur->right = new TreeNode(v);
                ans = cur->val;
                q.push(cur->right);
                break;
            } else {
                q.pop();
            }
        }
        return ans;
    }
    
    TreeNode* get_root() {
        return cbtroot;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
