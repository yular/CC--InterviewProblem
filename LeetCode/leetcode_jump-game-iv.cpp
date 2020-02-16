/*
*
* Tag: BFS
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    int minJumps(vector<int>& arr) {
        if(arr.size() < 2){
            return 0;
        }
        
        int n = arr.size();
        unordered_map<int, vector<int>> g;
        for(int i = 0; i < n; ++ i) {
            g[arr[i]].push_back(i);
        }
        
        vector<int> dis(n, n);
        dis[0] = 0;
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            
            for(int v : g[arr[u]]) {
                if(dis[v] > dis[u] + 1) {
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
            
            if(u > 0 && dis[u - 1] > dis[u] + 1) {
                dis[u - 1] = dis[u] + 1;
                q.push(u - 1);
            }
            if(u < n - 1 && dis[u + 1] > dis[u] + 1) {
                dis[u + 1] = dis[u] + 1;
                q.push(u + 1);
            }
            
            g[arr[u]].clear();
        }
        return dis[n - 1];
    }
};
