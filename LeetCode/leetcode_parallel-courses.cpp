/*
*
* Tag: Topological Sort
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        if(N == 0){
            return 0;
        }
        if(relations.size() == 0) {
            return 1;
        }
        
        unordered_map<int,vector<int>> g;
        vector<int> degCnt(N + 1, 0);
        for(vector<int> relation : relations){
            g[relation[0]].push_back(relation[1]);
            ++ degCnt[relation[1]];
        }
        
        queue<int> q;
        for(int i = 1; i <= N; ++ i){
            if(degCnt[i] == 0){
                q.push(i);
            }
        }
        
        int ans = 0, visCnt = 0;
        while(!q.empty()) {
            ++ ans;
            queue<int> nxtQ;
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                ++ visCnt;
                for(int v : g[u]) {
                    -- degCnt[v];
                    if(degCnt[v] == 0){
                        nxtQ.push(v);
                    }
                }
            }
            
            q = nxtQ;
        }
        return visCnt == N? ans : -1;
    }
};
