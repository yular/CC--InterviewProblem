/*
*
* Tag: Greedy + Union Find
* Time: O(elge + mlgm) e is the number of edges, m is the number of queries 
* Space: O(n)
*/


class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        if(edgeList.size() == 0 || queries.size() == 0) {
            return {};
        }
        
        int m = queries.size();
        for(int i = 0; i < m; ++ i) {
            queries[i].push_back(i);
        }
        
        sort(queries.begin(), queries.end(), [&](auto &a, auto &b) { return a[2] < b[2]; });
        sort(edgeList.begin(), edgeList.end(), [&](auto &a, auto &b) { return a[2] < b[2]; });
        
        int idx = 0;
        vector<bool> ans(m, false);
        vector<int> fa(n, -1);
        for(auto &q : queries){
            int u = q[0], v = q[1], limit = q[2];
            for(; idx < edgeList.size(); ++ idx) {
                int x = edgeList[idx][0], y = edgeList[idx][1], z = edgeList[idx][2];
                if(z >= limit) {
                    break;
                }
                unionSet(x, y, fa);
            }
            ans[q[3]] = isSameFa(u, v, fa);
        }
        return ans;
    }
private:
    void unionSet(int u, int v, vector<int> &fa) {
        int faU = findFa(u, fa), faV = findFa(v, fa);
        if(faU == faV) {
            return ;
        }
        
        if(fa[faU] <= fa[faV]) {
            fa[faV] = faU;
        } else {
            fa[faU] = faV;
        }
        return;
    }
    
    int findFa(int u, vector<int> &fa) {
        int s = u;
        for(; fa[s] >= 0; s = fa[s]) ;
        while(s != u) {
            int tmp = fa[u];
            fa[u] = s;
            u = tmp;
        }
        return s;
    }
    
    bool isSameFa(int u, int v, vector<int> &fa) {
        return findFa(u, fa) == findFa(v, fa);
    }
};
