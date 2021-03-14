/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        if(edges.size() == 0) {
            return 0;
        }
        
        int ans = 0, n = edges.size();
        vector<int> eCnt(n + 2, 0);
        for(vector<int> e : edges){
            int u = e[0], v = e[1];
            ++ eCnt[u], ++ eCnt[v];
            if(eCnt[u] == n) {
                ans = u;
            }
            if(eCnt[v] == n) {
                ans = v;
            }
        }
        return ans;
    }
};
