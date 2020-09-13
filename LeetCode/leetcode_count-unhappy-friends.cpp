/*
*
* Tag: Brute Force
* Time: O(n^2)
* Space: O(n)
*/

class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        if(n%2 != 0) {
            return 0;
        }
        
        vector<unordered_map<int, int>> dict(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < preferences[i].size(); ++j)
                dict[i][preferences[i][j]] = j;
        }
        
        vector<int> dist(n);
        for (vector<int> p : pairs) {
            dist[p[0]] = dict[p[0]][p[1]];
            dist[p[1]] = dict[p[1]][p[0]];
        }
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < dist[i]; ++j) {
                int u = preferences[i][j];
                for (int v = 0; v < dist[u]; ++v) {
                    if (i == preferences[u][v]) {
                        ++ ans;
                        j = v = n;
                    }
                }
            }
        }
        return ans;
    }
};
