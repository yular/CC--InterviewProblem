/*
*
* Tag: Greedy
* Time: O(nmlg(nm))
* Space: O(nm)
*/

class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int n = workers.size(), m = bikes.size();;
        vector<int> ans(n, -1);
        if(n == 0 || n > m) {
            return ans;
        }
        
        vector<vector<int>> edges(n*m);
        int idx = 0;
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < m; ++ j){
                edges[idx ++] = {i, j, caculateDist(workers[i], bikes[j])};
            }
        }
        
        sort(edges.begin(), edges.end(), cmp);
        
        vector<bool> isBikeUsed(m, false);
        int cnt = 0;
        for(vector<int> edge : edges){
            if(ans[edge[0]] == -1 && !isBikeUsed[edge[1]]) {
                ans[edge[0]] = edge[1];
                isBikeUsed[edge[1]] = true;
                ++ cnt;
            }
            if(cnt >= n) {
                break;
            }
        }
        
        return ans;
    }
private:
    struct comparator {
        bool operator() (const vector<int> &a, const vector<int> &b) {
            if(a[2] == b[2]) {
                if(a[0] == b[0])
                    return a[1] < b[1];
                else
                    return a[0] < b[0];
            }
            return a[2] < b[2];
        }
    }cmp;
    
    int caculateDist(vector<int> worker, vector<int> bike) {
        return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
    }
};
