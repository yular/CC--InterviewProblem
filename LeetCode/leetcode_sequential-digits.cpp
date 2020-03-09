/*
*
* Tag: Math
* Time: O(1)
* Space: O(1)
*/

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        if(low > high) {
            return {};
        }
        
        set<int> ans;
        for(int i = 1; i <= 9; ++ i){
            long long v = i;
            for(int j = i + 1; j  <= 9; ++ j){
                v = v*10 + j;
                if(v < low) {
                    continue;
                }
                if(v > high) {
                    break;
                }
                ans.insert(v);
            }
        }
        
        return vector(ans.begin(), ans.end());
    }
};
