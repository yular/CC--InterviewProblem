/*
*
* Tag: Greedy + Union Find
* Time: O(nmlog(nm))
* Space: O(nm)
* Credit: https://leetcode.com/problems/rank-transform-of-a-matrix/discuss/909212/C%2B%2B-Sort-%2B-Union-Find
*/

class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& mtx) {
        int n = mtx.size(), m = mtx[0].size();
        vector<vector<int>> arr;
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < m; ++j) {
                arr.push_back({mtx[i][j], i, j});
            }
        }
        
        sort(arr.begin(), arr.end(), cmp);
        
        vector<int> rows(n, 0), cols(m, 0);
        vector<pair<int, int>> group;
        int lastVal = INT_MIN;
        for (vector<int> &vec : arr) {
            int val = vec[0], r = vec[1], c = vec[2];
            if (val != lastVal) {
                fillGroupRank(mtx, group, cols, rows);
                lastVal = val;
                group.clear();
            }
            group.push_back({r, c});
        }
        fillGroupRank(mtx, group, cols, rows);
        return mtx;
    }
private:
    struct comparator {
        bool operator() (const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        }
    }cmp;
    
    void fillGroupRank(vector<vector<int>> &mtx, vector<pair<int, int>> &group, vector<int> &cols, vector<int> &rows) {
        vector<int> fa = vector<int>(mtx.size() + mtx[0].size(), -1);
        for (auto [r, c] : group) {
            auto faR = findFa(fa, r), faC = findFa(fa, rows.size() + c);
            if (faR != faC) {
                fa[faR] = min({fa[faR], fa[faC], -max(rows[r], cols[c]) - 1});
                fa[faC] = faR;
            }
        }
        for (auto [i, j] : group)
            mtx[i][j] = rows[i] = cols[j] = -fa[findFa(fa, i)];
    }
    
    int findFa(vector<int> &fa, int u) {
        int s = u;
        for(; fa[s] >= 0; s = fa[s]) ;
        while(s != u) {
            int tmp = fa[u];
            fa[u] = s;
            u = tmp;
        }
        return s;
    }
};
