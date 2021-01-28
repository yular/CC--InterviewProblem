/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    int findDistance(TreeNode* root, int p, int q) {
        if(root == NULL) {
            return -1;
        }
        if(p == q) {
            return 0;
        }
        
        unordered_map<int,int> dist;
        int ans = -1;
        int cnt = dfs(root, p, q, 0, dist, ans);
        return ans;
    }
private:
    int dfs(TreeNode* root, int p, int q, int dep, unordered_map<int,int> &dist, int &ans) {
        int cnt = 0;
        if(root->val == p || root->val == q) {
            ++ cnt;
        }
        
        dist[root->val] = dep;
        if(root->left) {
            cnt += dfs(root->left, p, q, dep + 1, dist, ans);
        }
        if(cnt == 2) {
            if(ans == -1) {
                ans = abs(dist[p] - dist[root->val]) + abs(dist[q] - dist[root->val]);
            }
            return cnt;
        }
        
        if(root->right) {
            cnt += dfs(root->right, p, q, dep + 1, dist, ans);
        }
        if(cnt == 2) {
            if(ans == -1) {
                ans = abs(dist[p] - dist[root->val]) + abs(dist[q] - dist[root->val]);
            }
        }
        
        return cnt;
    }
};
