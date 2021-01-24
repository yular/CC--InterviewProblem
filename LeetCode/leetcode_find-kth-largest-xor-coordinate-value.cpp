/*
*
* Tag: Data Structure Priority Queue
* Time: O(nmlgnm)
* Space: O(nm)
*/

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        if(matrix.size() == 0) {
            return 0;
        }
        
        int n = matrix.size(), m = matrix[0].size(), res = 0;
        vector<vector<int>> xorRes(n, vector<int>(m, 0));
        priority_queue<int,vector<int>, greater<int>> pq;
        for(int i = 0; i < n; ++ i){
            int v = 0;
            for(int j = 0; j < m; ++ j){
                v ^= matrix[i][j];
                int res = v;
                if(i > 0) {
                    res ^= xorRes[i - 1][j];
                }
                xorRes[i][j] = res;
                pq.push(res);
                if(pq.size() > k) {
                    pq.pop();
                }
            }
        }
        return pq.top();
    }
};
