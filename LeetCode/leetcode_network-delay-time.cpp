/*
*
* Tag: Graph
* Time: O(nlgn + m)
* Space: O(n)
*/

class Solution {
private:
    struct Node {
        int id, val;
        bool operator < (const Node &a)const{
            return a.val < val;
        }
    };
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        if(times.size() == 0 || N == 0) {
            return -1;
        }
        
        unordered_map<int, vector<pair<int,int>>> g;
        for(vector<int> time : times) {
            g[time[0]].push_back(make_pair(time[1], time[2]));
        }
        
        vector<int> dis(N + 1, INT_MAX);
        dis[K] = 0;
        priority_queue<Node> pq;
        Node node;
        node.id = K, node.val = 0;
        pq.push(node);
        
        vector<bool> vis(N + 1, false);
        int visCnt = 0;
        while(!pq.empty()) {
            Node cur = pq.top();
            pq.pop();
            
            int u = cur.id;
            if(!vis[u]) {
                ++ visCnt;
            }
            
            vis[u] = true;
            if(visCnt == N) {
                break;
            }
            for(pair<int,int> edge : g[u]) {
                int v = edge.first, val = edge.second;
                if(dis[u] + val < dis[v]) {
                    dis[v] = dis[u] + val;
                    Node node;
                    node.id = v, node.val = dis[v];
                    pq.push(node);
                }
            }
        }
        
        int ans = 0;
        for(int i = 1; i <= N; ++ i) {
            ans = max(ans, dis[i]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
