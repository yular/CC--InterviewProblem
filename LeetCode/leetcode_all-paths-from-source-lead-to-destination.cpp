/*
*
* Tag: DFS
* Time: O(n + m)
* Space: O(n + m)
*/

class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        if(edges.size() == 0 && source != destination){
            return false;
        }
        if(edges.size() == 0 && source == destination){
            return true;
        }
        
        vector<bool> visNodes(n, false), reachNodes(n, false);
        unordered_map<int,vector<int>> g;
        for(int i = 0; i < edges.size(); ++ i){
            if(edges[i][0] == destination) {
                return false;
            }
            g[edges[i][0]].push_back(i);
        }
        
        return canReachDst(source, destination, g, edges, visNodes, reachNodes);
    }
    
private:
    bool canReachDst(int src, int dst, unordered_map<int,vector<int>> &g, vector<vector<int>>& edges, vector<bool> &visNodes, vector<bool> &reachNodes) {
        if(src == dst){
            return true;
        }
        if(g[src].size() == 0){
            return false;
        }
        if(reachNodes[src]) {
            return true;
        }
        
        visNodes[src] = true;
        
        int numOfReachEdges = 0;
        for(int i = 0; i < g[src].size(); ++ i) {
            int edgeIdx = g[src][i];
            int nxt = edges[edgeIdx][1];
            if(visNodes[nxt]) {
                return false;
            }
            if(nxt == dst) {
                ++ numOfReachEdges;
                continue;
            }
            if(canReachDst(nxt, dst, g, edges, visNodes, reachNodes) == false){
                return false;
            } else {
                ++ numOfReachEdges;
            }
        }
        
        visNodes[src] = false;
        reachNodes[src] = numOfReachEdges == g[src].size();
        return reachNodes[src];
    }
};
