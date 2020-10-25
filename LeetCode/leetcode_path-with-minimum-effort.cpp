/*
*
* Tag: Graph + Dijkstra
* Time: O(nm + nmlog(nm) )
* Space: O(nm)
*/

class Solution {
private:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    struct node {
        int u, dis;
        node(int _u, int _dis) {
            u = _u, dis = _dis;
        }
        
        bool operator < (const node &a)const{
            return a.dis < dis;
        }
    };
    
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        if(heights.size() == 0 || heights[0].size() == 0) {
            return -1;
        }
        
        int n = heights.size(), m = heights[0].size();
        vector<vector<pair<int,int>>> g(n*m + 1);
        for(int i = 0; i < n; ++ i) {
            for(int j = 0; j < m; ++ j) {
                int u = i*m + j;
                for(int k = 0; k < 4; ++ k) {
                    int nxtR = i + dir[k][0], nxtC = j + dir[k][1];
                    if(nxtR < 0 || nxtR >= n || nxtC < 0 || nxtC >= m) {
                        continue;
                    }
                    
                    int v = nxtR*m + nxtC;
                    g[u].push_back(make_pair(v, abs(heights[i][j] - heights[nxtR][nxtC])));
                }
            }
        }
        
        vector<int> dis(n*m + 1, INT_MAX);
        dijkstra(dis, g, 0, n*m - 1);
        
        return dis[n*m - 1];
    }
    
private:
    void dijkstra(vector<int> &dis, vector<vector<pair<int, int>>> &g, int start, int end) {
        dis[start] = 0;
        
        priority_queue<node> pq;
        node nd = {start, 0};
        pq.push(nd);
        
        while(!pq.empty()) {
            node cur = pq.top();
            pq.pop();
            
            int u = cur.u;
            for(pair<int, int> edge : g[u]) {
                int v = edge.first, d = max(dis[u], edge.second);
                if(d < dis[v]) {
                    dis[v] = d;
                    node nxt = {v, dis[v]};
                    pq.push(nxt);
                }
            }
        }
        return ;
    }
};
