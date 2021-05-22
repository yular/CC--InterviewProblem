/*
*
* Tag: Two Pointers
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        if(encoded1.size() == 0 || encoded2.size() == 0) {
            return {};
        }
        
        int n = encoded1.size(), m = encoded2.size(), idx = 0;
        vector<vector<int>> ans;
        for(int i = 0, j = 0; i < n || j < m;) {
            int c = 0, v = encoded1[i][0]*encoded2[j][0];
            if(encoded1[i][1] > encoded2[j][1]) {
                encoded1[i][1] -= encoded2[j][1];
                c = encoded2[j][1];
                ++ j;
            } else if(encoded1[i][1] < encoded2[j][1]) {
                encoded2[j][1] -= encoded1[i][1];
                c = encoded1[i][1];
                ++ i;
            } else {
                c = encoded1[i][1];
                ++ i, ++ j;
            }
            if(idx > 0 && ans[idx - 1][0] == v) {
                ans[idx - 1][1] += c;
                continue;
            }
            ans.push_back({v, c});
            ++ idx;
        }
        return ans;
    }
};
