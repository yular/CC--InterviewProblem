/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        if(n == 0 || edges.size() == 0) {
            return {};
        }
        
        vector<vector<int>> tree(n);
        for(vector<int> &edge : edges) {
            int u = edge[0], v = edge[1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        
        vector<int> ans(n, 0);
        vector<vector<int>> dp(n, vector<int>(26, 0));
        dfs(0, -1, tree, ans, dp, labels);
        
        return ans;
    }
private:
    void dfs(int u, int parent, vector<vector<int>> &tree, vector<int> &ans, vector<vector<int>> &dp, string &labels) {
        ++ dp[u][labels[u] - 'a'];
        
        for(int &v : tree[u]) {
            if(v == parent) {
                continue;
            }
            
            dfs(v, u, tree, ans, dp, labels);
            for(int i = 0; i < 26; ++ i) {
                dp[u][i] += dp[v][i];
            }
        }
        
        ans[u] = dp[u][labels[u] - 'a'];
        return ;
    }
};
