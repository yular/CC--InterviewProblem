/*
*
* Tag: Data Structure Binary Index Tree
* Time: O(nqlgm + nlgm)
* Space: O(m + n^2)
*/

class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        if(queries.size() == 0) {
            return {};
        } 
        
        vector<int> indeg(n + 1, 0);
        vector<vector<int>> g(n + 1);
        int maxVal = 0;
        for(vector<int> &edge : edges ) {
            ++ indeg[edge[0]], ++ indeg[edge[1]];
            maxVal = max(maxVal, indeg[edge[0]]);
            maxVal = max(maxVal, indeg[edge[1]]);
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        
        vector<int> tree(maxVal + 10, 0);
        initTree(indeg, tree);
        
        int m = queries.size();
        vector<int> ans(m, 0);
        for(int i = 1; i <= n; ++ i) {
            updateTree(indeg[i], -1, tree);
            for(int v : g[i]) {
                if(v > i) {
                    updateTree(indeg[v], -1, tree);
                    -- indeg[v];
                    updateTree(indeg[v], 1, tree);
                }
            }
            for(int q = 0; q < m; ++ q) {
                if(indeg[i] > queries[q]) {
                    ans[q] += n - i;
                } else {
                    int diff = queries[q] + 1 - indeg[i];
                    ans[q] += (sumTree(maxVal + 2, tree) - sumTree(diff - 1, tree));
                }
            }
            for(int v : g[i]) {
                if(v > i) {
                    updateTree(indeg[v], -1, tree);
                    ++ indeg[v];
                    updateTree(indeg[v], 1, tree);
                }
            }
        }
        return ans;
    }
private:
    void initTree(vector<int> &indeg,  vector<int> &tree) {
        for(int v : indeg) {
            if(v == 0) {
                continue;
            }
            updateTree(v, 1, tree);
        }
    }
    
    void updateTree(int startIdx, int v, vector<int> &tree) {
        for(int i = startIdx + 1; i < tree.size(); i += lowbit(i)) {
            tree[i] += v;
        }
    }
    
    int sumTree(int startIdx, vector<int> &tree) {
        int res = 0;
        for(int i = min(startIdx + 1, (int)tree.size() - 1); i > 0; i -= lowbit(i)) {
            res += tree[i];
        }
        return res;
    }
    
    int lowbit(int x) {
        return x&-x;
    }
};
