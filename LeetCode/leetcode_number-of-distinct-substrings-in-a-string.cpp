/*
*
* Tag: Rolling Hash
* Time: O(n)
* Space: O(n^2)
*/

class Solution {
private:
    long long MOD = 3e11 + 7;
public:
    int countDistinct(string s) {
        if(s.size() == 0) {
            return 0;
        }
        
        int ans = 0;
        unordered_set<long long> vis;
        for(int i = 0; i < s.size(); ++ i){
            long long v = 0;
            for(int j = i; j < s.size(); ++ j){
                v = (v*26 + (s[j] - 'a' + 1))%MOD;
                if(vis.count(v) == 0) {
                    vis.insert(v);
                    ++ ans;
                }
            }
        }
        return ans;
    }
};
