/*
*
* Tag: Graph, Dijkstra
* Time: O((m + n)lgn)
* Space: O(n + m)
*/

class Solution {
private:
    const double eps = 1e-5;
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        if(n == 0 || edges.size() == 0) {
            return 0.0;
        }
        
        int m = edges.size();
        vector<vector<pair<int,long double>>> g(n);
        for(int i = 0; i < m; ++ i) {
            int u = edges[i][0], v = edges[i][1];
            g[u].push_back(make_pair(v, 1/succProb[i]));
            g[v].push_back(make_pair(u, 1/succProb[i]));
        }
        
        vector<long double> dis(n, LDBL_MAX);
        dijkstra(dis, g, start, end);
        
        return 1/dis[end];
    }
    
private:
    struct node {
        int u;
        long double dis;
        node(int _u, long double _dis) {
            u = _u, dis = _dis;
        }
        
        bool operator < (const node &a)const{
            return a.dis < dis;
        }
    };
    
    void dijkstra(vector<long double> &dis, vector<vector<pair<int,long double>>> &g, int start, int end){
        dis[start] = 1;
        
        priority_queue<node> pq;
        node nd = {start, 1};
        pq.push(nd);
        
        while(!pq.empty()) {
            node cur = pq.top();
            pq.pop();
            
            int u = cur.u;
            for(pair<int,double> edge : g[u]) {
                int v = edge.first;
                if(dis[u]*edge.second < dis[v]) {
                    dis[v] = dis[u]*edge.second;
                    node nxt = {v, dis[v]};
                    pq.push(nxt);
                }
            }
        }
        return ;
    }
};
