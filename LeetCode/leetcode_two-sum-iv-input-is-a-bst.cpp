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
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) {
            return false;
        }
        
        vector<int> arr;
        getAllValuesOf(root, arr);
        
        return canFindTwoSumTarget(arr, k);
    }
private:
    void getAllValuesOf(TreeNode* root, vector<int> &arr) {
        if(root == NULL) {
            return ;
        }
        
        getAllValuesOf(root->left, arr);
        arr.push_back(root->val);
        getAllValuesOf(root->right, arr);
    }
    
    bool canFindTwoSumTarget(vector<int> &arr, int k) {
        for(int leftIdx = 0, rightIdx = arr.size() - 1; leftIdx < rightIdx; ) {
            int sum = arr[leftIdx] + arr[rightIdx];
            if(sum == k) {
                return true;
            }
            if(sum < k) {
                ++ leftIdx;
            } else {
                -- rightIdx;
            }
        }
        
        return false;
    }
};
