/*
*
* Tag: DFS
* Time: O(n + m) where n is number of vertex and m is number of edge
* Space: O(n^2)
*/
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> ans;
        if(n == 0){
            return ans;
        }
        
        vector<int> g[n];
        for(vector<int> connection : connections){
            g[connection[0]].push_back(connection[1]);
            g[connection[1]].push_back(connection[0]);
        }
        
        vector<int> father(n, -1);
        vector<int> dfn(n, -1);
        vector<int> low(n, -1);
        int tim = 0;
        
        tarjan(0, -1, g, father, dfn, low, tim);
        
        for(int i = 0; i < n;++i){
            int v = father[i];
            if(v >= 0 && low[i] > dfn[v]){
                vector<int> bridge = {v, i};
                ans.push_back(bridge);
            }
        }
        return ans;
    }
    
private:
    void tarjan(int i,int Father, vector<int> g[], vector<int> &father, vector<int> &dfn, vector<int> &low, int &tim) {
        father[i] = Father;
        dfn[i] = low[i] = tim++;
        for(int j = 0;j < g[i].size();++j){
            int k = g[i][j];
            if(dfn[k] == -1) {
                tarjan(k, i, g, father, dfn, low, tim);
                low[i] = min(low[i], low[k]);
            } else if(Father != k) {
                low[i] = min(low[i], dfn[k]);
            }
        }
        
        return ;
    }
    
};
