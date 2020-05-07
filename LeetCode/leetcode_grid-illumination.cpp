/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/

class Solution {
private:
    const int dir[9][2] = {{0,1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}, {0, 0}};
public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        if(queries.size() == 0) {
            return {};
        }
        
        unordered_map<int,int> rDic, cDic, dDic, adDic;
        unordered_map<int,unordered_set<int>> lampDict;
        for(vector<int> lamp:lamps) {
            ++ rDic[lamp[0]];
            ++ cDic[lamp[1]];
            ++ dDic[lamp[0] + lamp[1]];
            ++ adDic[lamp[0] - lamp[1]];
            lampDict[lamp[0]].insert(lamp[1]);
        }
        
        vector<int> ans(queries.size(), 0);
        for(int i = 0; i < queries.size(); ++ i) {
            int r = queries[i][0], c = queries[i][1];
            if(rDic[r] > 0 || cDic[c] > 0 || dDic[r + c] > 0 || adDic[r - c] > 0) {
                ans[i] = 1;
            }
            
            for(int j = 0; j < 9; ++ j) {
                int nxt_r = r + dir[j][0], nxt_c = c + dir[j][1];
                if(nxt_r < 0 || nxt_r >= N || nxt_c < 0 || nxt_c >= N) {
                    continue;
                }
                
                if(lampDict.count(nxt_r) > 0 && lampDict[nxt_r].count(nxt_c) > 0) {
                    -- rDic[nxt_r];
                    -- cDic[nxt_c];
                    -- dDic[nxt_c + nxt_r];
                    -- adDic[nxt_r - nxt_c];
                    lampDict[nxt_r].erase(nxt_c);
                }
            }
        }
        return ans;
    }
};
