/*
*
* Tag: DFS + Sort
* Time:  O(nlgn)
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
    struct Node {
        int x, y, val;
        Node(int _x, int _y, int _v): x(_x), y(_y), val(_v) {}
        bool operator < (const Node &a)const{
            if(x != a.x) {
                return x < a.x;
            }
            if(y != a.y) {
                return a.y < y;
            }
            return val < a.val;
        }
    };
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        vector<Node> nodes;
        dfs(root, nodes, 0, 0);
        sort(nodes.begin(), nodes.end());
        int pos = -1, lastX = 0;
        for(int i = 0; i < nodes.size(); ++ i) {
            Node node = nodes[i];
            if(i == 0 || node.x != lastX) {
                vector<int> verticalLevel;
                ans.push_back(verticalLevel);
                ++ pos;
            }
            ans[pos].push_back(node.val);
            lastX = node.x;
        }
        return ans;
    }
private:
    void dfs(TreeNode* root, vector<Node> &nodes, int x, int y) {
        if(root == NULL) {
            return ;
        }
        Node node(x, y, root->val);
        nodes.push_back(node);
        dfs(root->left, nodes, x - 1, y - 1);
        dfs(root->right, nodes, x + 1, y - 1);
    }
};
