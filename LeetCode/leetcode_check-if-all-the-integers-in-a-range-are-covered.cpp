/*
*
* Tag: Hash
* Time: O(nm)
* Space: O(1)
*/
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        if(ranges.size() == 0) {
            return false;
        }
        
        vector<bool> vis(100, false);
        for(vector<int> rng : ranges) {
            for(int i = rng[0]; i <= rng[1]; ++ i) {
                vis[i] = true;
            }
        }
        
        for(int i = left; i <= right; ++ i) {
            if(!vis[i]) {
                return false;
            }
        }
        return true;
    }
};
