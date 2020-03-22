/*
*
* Tag: Sort 
* Time: O(nlgn) + O(nm)
* Space: O(lgn)
*/

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        if(mat.size() == 0 || k == 0) {
            return {};
        }
        
        int n = mat.size(), m = mat[0].size();
        vector<pair<int,int>> matinfo(n);
        for(int i = 0; i < n; ++ i){
            int cnt = 0;
            for(int j = 0; j < m; ++ j) {
                if(mat[i][j] == 1) {
                    ++ cnt;
                }
            }
            matinfo[i] = make_pair(i, cnt);
        }
        
        sort(matinfo.begin(), matinfo.end(), cmp);
        
        vector<int> ans(k);
        for(int i = 0; i < k; ++ i) {
            ans[i] = matinfo[i].first;
        }
        return ans;
    }
    
private:
    struct comparator {
        bool operator() (const pair<int,int> &a, const pair<int,int> &b) {
            if(a.second == b.second) {
                return a.first < b.first;
            }
            return a.second < b.second;
        }
    }cmp;
};
