/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        if(dominoes.size() == 1) {
            return 0;
        }
        
        int n = dominoes.size();
        unordered_map<int, unordered_map<int,int>> cnt;
        for(int i = 0; i < n; ++ i) {
            if(dominoes[i][0] > dominoes[i][1]) {
                swap(dominoes[i][0], dominoes[i][1]);
            }
            ++ cnt[dominoes[i][0]][dominoes[i][1]];
        }
        
        int ans = 0;
        for(auto i : cnt) {
            for(auto j : i.second) {
                int v = j.second;
                ans += v*(v - 1)/2;
            }
        }
        return ans;
    }
};
