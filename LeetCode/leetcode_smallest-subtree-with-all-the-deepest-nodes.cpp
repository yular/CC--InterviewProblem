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
    TreeNode* ans;
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        ans = NULL;
        if(root == NULL){
            return root;
        }
        
        int largestDepth = -1, numOfDeepestLeaves = 0;
        getLargestDepth(0, largestDepth, numOfDeepestLeaves, root);
        if(largestDepth == 0){
            return root;
        }
        
        bool isFound = false;
        getNumOfDeepestNodesOf(root, largestDepth, numOfDeepestLeaves, 0, isFound);
        return ans;
    }
    
private:
    void getLargestDepth(int curDepth, int &largestDepth, int &numOfDeepestLeaves, TreeNode* root){
        if(root == NULL){
            return ;
        }
        if(largestDepth == curDepth){
            ++ numOfDeepestLeaves;
        } else if(largestDepth < curDepth) {
            numOfDeepestLeaves = 1;
            largestDepth = max(largestDepth, curDepth);
        }
        getLargestDepth(curDepth + 1, largestDepth, numOfDeepestLeaves, root->left);
        getLargestDepth(curDepth + 1, largestDepth, numOfDeepestLeaves, root->right);
    }
    
    int getNumOfDeepestNodesOf(TreeNode *root, int largestDepth, int numOfDeepestLeaves, int curDepth, bool &isFound){
        if(root == NULL) {
            return 0;
        }
        
        int sum = 0;
        if(root->left != NULL) {
            sum += getNumOfDeepestNodesOf(root->left, largestDepth, numOfDeepestLeaves, curDepth + 1, isFound);
        }
        if(isFound) {
            return sum;
        }
        if(root->right != NULL) {
            sum += getNumOfDeepestNodesOf(root->right, largestDepth, numOfDeepestLeaves, curDepth + 1, isFound);
        }
        if(isFound) {
            return sum;
        }
        
        if(sum == numOfDeepestLeaves) {
            isFound = true;
            ans = root;
            return sum;
        }
        
        if(curDepth == largestDepth) {
            if(numOfDeepestLeaves == 1) {
                isFound = true;
                ans = root;
            }
            return 1;
        }
        return sum;
    }
};
