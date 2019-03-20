/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n^2)
*/
class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        int ans = 0;
        if(N == 0){
            return ans;
        }
        
        vector<vector<bool>> graph(N, vector<bool>(N, true));
        for(vector<int> mine : mines) {
            graph[mine[0]][mine[1]] = false;
        }
        
        vector<vector<vector<int>>> aggSum(4, vector<vector<int>>(N, vector<int>(N, 0)));
        for(int i = 0; i < N; ++ i){
            aggSum[0][i][0] = graph[i][0]? 1 : 0;
            aggSum[1][0][i] = graph[0][i]? 1 : 0;
            aggSum[2][i][N - 1] = graph[i][N - 1]? 1 : 0;
            aggSum[3][N - 1][i] = graph[N - 1][i]? 1 : 0;
            if(graph[i][0] || graph[0][i] || graph[i][N - 1] || graph[N - 1][i]) {
                ans = 1;
            }
        }
        for(int i = 1; i < N - 1; ++ i){
            for(int j = 1; j < N - 1; ++ j){
                aggSum[0][i][j] = graph[i][j]? aggSum[0][i][j - 1] + 1 : 0;
                aggSum[1][i][j] = graph[i][j]? aggSum[1][i - 1][j] + 1 : 0;
                aggSum[2][i][N - 1 - j] = graph[i][N - 1 - j]? aggSum[2][i][N - j] + 1 : 0;
                aggSum[3][N - 1 - i][j] = graph[N - 1 - i][j]? aggSum[3][N - i][j] + 1 : 0;
            }
        }
        
        for(int i = 1; i < N - 1; ++ i){
            for(int j = 1; j < N - 1; ++ j){
                if(graph[i][j] == false){
                    continue;
                }
                
                int v = 1 + min(aggSum[0][i][j - 1], min(aggSum[1][i - 1][j], min(aggSum[2][i][j + 1], aggSum[3][i + 1][j] )));
                ans = max(ans, v);
            }
        }
        
        return ans;
    }
};
