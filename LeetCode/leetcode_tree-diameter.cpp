/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n^2)
*/

class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        if(edges.size() == 0) {
            return 0;
        }
        
        unordered_map<int,vector<int>> tree;
        for(vector<int> edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> vis(edges.size(), false);
        int ans = 0, root = 0;
        dfs(tree, root, vis, ans);      
        return ans;
    }
    
private:
    int dfs(unordered_map<int,vector<int>> &tree, int root, vector<bool> &vis, int &ans) {
        if(tree[root].size() == 0){
            return 0;
        }
        vis[root] = true;
        
        int maxLen = -1, secondMaxLen = -1, res = 0;
        for(int u : tree[root]) {
            if(vis[u]) {
                continue;
            }
            
            int len = dfs(tree, u, vis, ans) + 1;
            if(len >= maxLen) {
                secondMaxLen = maxLen;
                maxLen = len;
            } else if(len >= secondMaxLen) {
                secondMaxLen = len;
            }
        }
        if(maxLen == -1 && secondMaxLen == -1) {
            return 0;
        }
        if(secondMaxLen == -1) {
            res = maxLen;
        } else {
            res = maxLen + secondMaxLen;
        }
        
        ans = max(ans, res);
        return maxLen;
    }
};
