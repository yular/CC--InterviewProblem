/*
*
* Tag: DFS + Bit Manipulation
* Time: O(n*2^n)
* Space: O(n)
*/

class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        if(n == 0 || edges.size() != n - 1) {
            return {};
        }
        
        vector<vector<int>> tree(n);
        for(vector<int> edge : edges) {
            int u = edge[0] - 1, v = edge[1] - 1;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        
        vector<int> ans(n - 1);
        int tot = 1<<n;
        for(int state = 3; state < tot; ++ state) {
            for(int i = 0; i < n; ++ i){
                if((state&(1<<i)) > 0) {
                    int cnt = 0, res = 0;
                    dfs(i, state^(1<<i), tree, cnt, res);
                    if(res > 0 && cnt == getDigitCnt(state)) {
                        ++ ans[res - 1];
                    }
                    break;
                }
            }
        }
        return ans;
    }
private:
    int dfs(int u, int state, vector<vector<int>> &tree, int &cnt, int &res) {
        ++ cnt;
        
        int maxDia = 0;
        for(int v : tree[u]) {
            if((state&(1<<v)) > 0) {
                int dia = 1 + dfs(v, state^(1<<v), tree, cnt, res);
                res = max(res, dia + maxDia);
                maxDia = max(maxDia, dia);
            }
        }
        return maxDia;
    }
    
    int getDigitCnt(int v) {
        int res = 0;
        for(; v > 0; res += (v&1), v >>= 1) ;
        return res;
    }
};
