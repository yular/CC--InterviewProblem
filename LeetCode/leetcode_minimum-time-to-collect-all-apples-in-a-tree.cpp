/*
*
* Tag: DFS
* Time: O(n + m)
* Space: O(n)
*/

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        if(n == 0 || edges.size() == 0) {
            return 0;
        }
        
        unordered_map<int,vector<int>> tree;
        for(vector<int> edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> hasTreeApple = hasApple, vis(hasApple.size(), false);
        int ans = 0;
        getAppleCollectionTime(tree, 0, hasTreeApple, vis, ans);
        
        return ans;
    }
private:
    void getAppleCollectionTime(unordered_map<int,vector<int>> &tree, int root, vector<bool> &hasTreeApple, vector<bool> &vis, int &ans) {
        vis[root] = true;
        for(int v : tree[root]) {
            if(vis[v]) {
                continue;
            }
            
            getAppleCollectionTime(tree, v, hasTreeApple, vis, ans);
            
            if(hasTreeApple[v]) {
                hasTreeApple[root] = true;
                ans += 2;
            }
        }
        vis[root] = false;
    }
};
