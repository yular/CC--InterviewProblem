/*
*
* Tag: Hash
* Time: O(m + n^2)
* Space: O(n^2)
*/
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        if(n == 0  || roads.size() == 0) {
            return 0;
        }
        
        vector<int> edgeCnt(n, 0);
        unordered_map<int,map<int,int>> pairCnt;
        for(vector<int> rd : roads) {
            int u = rd[0], v = rd[1];
            ++ edgeCnt[u], ++ edgeCnt[v];
            ++ pairCnt[u][v], ++ pairCnt[v][u];;
        }
        
        int ans = 0;
        for(int i = 0; i < n; ++ i) {
            for(int j = i + 1; j < n; ++ j) {
                ans = max(edgeCnt[i] + edgeCnt[j] - pairCnt[i][j], ans);
            }
        }
        return ans;
    }
};
