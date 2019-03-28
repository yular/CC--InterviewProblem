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
private:
    TreeNode *root;
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        root = NULL;
        if(preorder.size() == 0){
            return root;
        }
        
        buildBST(preorder, 0, preorder.size(), &root);
        return root;
    }
private:
    void buildBST(vector<int>& preorder, int startIdx, int endIdx, TreeNode **root) {
        *root = new TreeNode(preorder[startIdx]);
        if(startIdx + 1 == endIdx) {
            return;
        }
        
        int rightChildIdx = startIdx + 1, i;
        for(i = startIdx + 1; i < endIdx; ++ i) {
            if(preorder[i] > preorder[startIdx] ) {
                rightChildIdx = i;
                break;
            }
        }
        if(i > startIdx + 1) {
            buildBST(preorder, startIdx + 1, i, &((*root)->left));
        }
        if(i < endIdx) {
            buildBST(preorder, rightChildIdx, endIdx, &((*root)->right));
        }
        return;
    }
};
