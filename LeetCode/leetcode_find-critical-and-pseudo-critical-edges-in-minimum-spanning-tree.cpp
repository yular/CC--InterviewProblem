/*
*
* Tag: Graph (MST)
* Time: O((m^2)lgm)
* Space: O(n + m)
*/

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        if(edges.size() < n - 1) {
            return {{}, {}};
        }
        
        int m = edges.size();
        vector<vector<int>> idEdges(m);
        for(int i = 0; i < m; ++ i) {
            idEdges[i] = {edges[i][0], edges[i][1], edges[i][2], i};
        }
        sort(idEdges.begin(), idEdges.end(), cmp);
        
        int maxEdge = 0;
        int cost = getMSPCost(n, idEdges, -1, -1, maxEdge);
        vector<vector<int>> ans(2, vector<int>(0));
        for(int i = 0; i < m; ++ i) {
            if(idEdges[i][2] > maxEdge) {
                break;
            }
            
            int curMaxEdge = 0;
            int curCost = getMSPCost(n, idEdges, i, -1, curMaxEdge), id = idEdges[i][3];
            
            if(curCost > cost) {
                ans[0].push_back(id);
            } else {
                curCost = getMSPCost(n, idEdges, -1, i, curMaxEdge);
                if(curCost > cost) {
                    continue;
                }
                ans[1].push_back(id);
            }
        }
        
        return ans;
    }
    
private:
    int getMSPCost(int n, vector<vector<int>>& edges, int skipId, int mustId, int &maxEdge) {
        int cost = 0, m = edges.size();
        vector<int> fa(n, -1);
        
        if(mustId != -1) {
            int u = edges[mustId][0], v = edges[mustId][1];
            unionSet(u, v, fa);
            cost += edges[mustId][2];
        }
        
        for(int i = 0; i < m; ++ i) {
            if(i == skipId) {
                continue;
            }
            
            int u = edges[i][0], v = edges[i][1];
            if(findFa(u, fa) == findFa(v, fa)) {
                continue;
            }
            
            unionSet(u, v, fa);
            cost += edges[i][2];
            maxEdge = max(maxEdge, edges[i][2]);
        }
        
        int ndCnt = 0;
        for(int i = 0; i < n; ++ i) {
            if(fa[i] >= 0) {
                continue;
            }
            
            ++ ndCnt;
        }
        return ndCnt == 1? cost : INT_MAX;
    }
    
    int findFa(int u, vector<int> &fa) {
        int s = u;
        for(; fa[s] >= 0; s = fa[s]);
        
        while(s != u) {
            int tmp = fa[u];
            fa[u] = s;
            u = tmp;
        }
        return s;
    }
    
    void unionSet(int u, int v, vector<int> &fa) {
        int faU = findFa(u, fa), faV = findFa(v, fa);
        if(fa[faU] <=  fa[faV]) {
            fa[faV] = faU;
        } else {
            fa[faU] = faV;
        }
        return ;
    }
    
    struct comparator {
        bool operator() (const vector<int> &a, const vector<int> &b) {
            return a[2] < b[2];
        }
    }cmp;
};
