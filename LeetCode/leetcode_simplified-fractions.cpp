/*
*
* Tag: Math
* Time: O((n^2)lgn)
* Space: O(1)
*/

class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        if(n < 2) {
            return {};
        }
        
        vector<string> ans;
        for(int i = 2; i <= n; ++ i) {
            for(int j = 1; j < i; ++ j) {
                if(__gcd(j, i) > 1) {
                    continue;
                }
                
                string res = to_string(j) + "/" + to_string(i);
                ans.push_back(res);
            }
        }
        return ans;
    }
};
