/*
*
* Tag: Graph, Network flow
* Time: O() ???
* Space: O(n^2)
*/

class Solution {
private:
    const int MAXN = 5000 + 50;
    
    struct Edge {
        int fr, to, residual, cost;
    };
    vector<Edge> edges;
    vector<int> G[5050];
    int s, t, maxFlow, minCost;
    int last[5050], flow[5050], dis[5050];
    bool inQueue[5050];
    
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        if(workers.size() == 0 || bikes.size() == 0) {
            return 0;
        }
        
        int n = workers.size(), m = bikes.size();
        s = 0, t = n + m + 1;
        maxFlow = minCost = 0;
        
        for(int u = 1; u <= n; ++ u) {
            for(int v = n + 1; v <= n + m; ++ v) {
                int cost = calCost(workers[u - 1], bikes[v - n - 1]);
                G[u].push_back(edges.size()); 
                edges.push_back({ u, v, 1, cost });
		        G[v].push_back(edges.size()); 
                edges.push_back({ v, u, 0, -cost });
            }
        }
        
        for(int i = 1; i <= n; ++ i) {
            G[s].push_back(edges.size()); 
            edges.push_back({ s, i, 1, 0 });
            G[i].push_back(edges.size()); 
            edges.push_back({ i, s, 0, 0 });
        }
        
        for(int i = n + 1; i <= n + m; ++ i) {
            Edge edge1, edge2;
            edge1.fr = i, edge1.to = t, edge1.residual = 1, edge1.cost = 0;
            G[i].push_back(edges.size()); 
            edges.push_back(edge1);
            
            G[t].push_back(edges.size()); 
            edge2.fr = t, edge2.to = i, edge2.residual = 0, edge2.cost = 0;
            edges.push_back({ t, i, 0, 0 });
        }
        
	    while (SPFA());
        
        return minCost;
    }
    
private:
    bool SPFA() {
        memset(inQueue, false, sizeof(inQueue)); 
        fill(dis, dis + MAXN, INT_MAX);
        queue<int> que; 
        que.push(s);
        
        inQueue[s] = true; 
        flow[s] = INT_MAX; last[s] = 0; dis[s] = 0;

        int nowAt;
        while (!que.empty()) {
            nowAt = que.front(); 
            que.pop(); 

            inQueue[nowAt] = false;
            for (int i = 0; i < G[nowAt].size(); i++) {
                Edge& it = edges[G[nowAt][i]];
                if (it.residual > 0 && dis[it.to] > dis[nowAt] + it.cost) {
                    dis[it.to] = dis[nowAt] + it.cost;
                    last[it.to] = G[nowAt][i];
                    flow[it.to] = min(flow[nowAt], it.residual);
                    if (!inQueue[it.to]) { inQueue[it.to] = true; que.push(it.to); }
                }
            }
        }
        if (dis[t] == INT_MAX) {
            return false;
        }

        maxFlow += flow[t]; minCost += dis[t] * flow[t];
        nowAt = t;
        while (nowAt != s) {
            edges[last[nowAt]].residual -= flow[t];
            edges[last[nowAt] ^ 1].residual += flow[t];
            nowAt = edges[last[nowAt]].fr;
        }
        return true;
    }
    
    int calCost(vector<int> &a, vector<int> &b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
};
