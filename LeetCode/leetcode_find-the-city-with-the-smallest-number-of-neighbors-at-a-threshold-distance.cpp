/*
*
* Tag: Graph
* Time: O(n^3)
* Space: O(1)
*/
class Solution {
private:
    const int MAX_DIS = 1e6;
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        if(distanceThreshold == 0) {
            return -1;
        }
        
        vector<vector<int>> g(n, vector<int>(n, MAX_DIS));
        for(int i = 0; i < n; ++ i){
            g[i][i] = 0;
        }
        for(vector<int> edge : edges){
            g[edge[0]][edge[1]] = edge[2];
            g[edge[1]][edge[0]] = edge[2];
        }
        
        for(int k = 0; k < n; ++ k){
            for(int i = 0; i < n; ++ i){
                for(int j = 0; j < n; ++ j){
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
        
        int ans = 0, maxCnt = n;
        for(int i = 0; i < n; ++ i){
            int cnt = 0;
            for(int j = 0; j < n; ++ j){
                if(i != j  && g[i][j] <= distanceThreshold) {
                    ++ cnt;
                }
            }
            if(cnt <= maxCnt){
                maxCnt = cnt;
                ans = i;
            }
        }
        return ans;
    }
};
