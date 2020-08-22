/*
*
* Tag: Statistics
* Time: O(n+m)
* Space: o(n)
*/

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        if(edges.size() == 0 || n == 0) {
            return {};
        }
        
        int m = n;
        vector<int> inDeg(n, 0);
        for(vector<int> edge :  edges) {
            ++ inDeg[edge[1]];
            if(inDeg[edge[1]] == 1) {
                -- m;
            }
        }
        if(m == 0) {
            return {0};
        }
        
        vector<int> ans(m, 0);
        for(int i = 0, idx = 0; i < n, idx < m; ++ i) {
            if(inDeg[i] == 0) {
                ans[idx ++] = i;
            }
        }
        
        return ans;
    }
};
