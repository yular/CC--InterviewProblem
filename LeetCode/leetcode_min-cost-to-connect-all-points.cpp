/*
*
* Tag: MST
* Time: O(m^2 + n*lgm) n is the number vertexes, and m is the number of edges.
* Space: O(m^2)
*/

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        if(points.size() < 2) {
            return 0;
        }
        
        int n = points.size(), idx = 0;
        vector<vector<int>> edges(n*(n - 1)/2);
        for(int i = 0; i < n; ++ i) {
            for(int j = i + 1; j < n; ++ j) {
                int dis = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges[idx ++] = {dis, i, j};
            }
        }
        
        make_heap(edges.begin(), edges.end(), greater<vector<int>>());
        
        int ans = 0, cnt = 0;
        vector<int> fa(n, -1);
        while (!edges.empty()) {
            pop_heap(edges.begin(), edges.end(), greater<vector<int>>());
            vector<int> edge = edges.back();
            edges.pop_back();
            
            int u = edge[1], v = edge[2];
            if(findFa(u, fa) == findFa(v, fa)) {
                continue;
            }
            
            ans += edge[0];
            unionEdge(u, v, fa);
            ++ cnt;
            if(cnt == n - 1) {
                break;
            }
        }
        return ans;
    }
    
private:
    void unionEdge(int u, int v, vector<int> &fa) {
        int faU = findFa(u, fa), faV = findFa(v, fa);
        if(fa[faU] <= fa[faV]) {
            fa[faV] = faU;
        } else {
            fa[faU] = faV;
        }
        return ;
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
    
private:
    struct comparator{
        bool operator() (vector<int> &a, vector<int> &b) {
            return a[2] < b[2];
        }
    }cmp;
};
