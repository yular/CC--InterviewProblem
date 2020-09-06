/*
*
* Tag: Union Find
* Time: O(m)
* Space: O(n + m)
*/

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        if(n == 0 || m < n - 1) {
            return -1;
        }
        
        vector<int> fa(n + 1, -1);
        vector<bool> used(m, false);
        int cnt = unionSet(fa, edges, used, 3), ans = 0;
        if(cnt == 1) {
            for(int i = 0; i < m; ++ i) {
                if(!used[i]) {
                    ++ ans;
                }
            }
            return ans;
        }
        
        for(int i = 0; i < m; ++ i) {
            if(!used[i] && edges[i][0] == 3) {
                ++ ans;
            }
        }
        
        for(int type = 1; type < 3; ++ type){
            vector<int> curFa = fa;
            vector<bool> curUsed = used;
            int cnt = unionSet(curFa, edges, curUsed, type);
            if(cnt != 1) {
                return -1;
            }
            
            for(int i = 0; i < m; ++ i) {
                if(!curUsed[i] && edges[i][0] == type) {
                    ++ ans;
                }
            }
        }
        return ans;
    }
private:
    int unionSet(vector<int> &fa, vector<vector<int>> &edges, vector<bool> &used, int type) {
        int m = edges.size();
        for(int i = 0; i < m; ++ i) {
            int u = edges[i][1], v = edges[i][2];
            if(edges[i][0] != type || findFa(u, fa) == findFa(v,fa)) {
                continue;
            }
            
            unionEdge(u, v, fa);
            used[i] = true;
        }
        
        int cnt = 0;
        for(int i = 1; i < fa.size(); ++ i) {
            if(fa[i] == -1) {
                ++ cnt;
            }
        }
        return cnt;
    }
    
    void unionEdge(int u, int v, vector<int> &fa) {
        int faU = findFa(u, fa), faV = findFa(v, fa);
        if(fa[faU] <= fa[faV]) {
            fa[faV] = u;
        } else {
            fa[faU] = v;
        }
        return ;
    }
    
    int findFa(int u, vector<int> &fa) {
        int s = u;
        for(; fa[s] >= 0; s = fa[s]) ;
        while(u != s) {
            int tmp = fa[u];
            fa[u] = s;
            u = tmp;
        }
        return s;
    }
};
