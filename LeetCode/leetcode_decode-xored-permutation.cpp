/*
*
* Tag: Bit Manipulation
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        if(encoded.size() < 2) {
            return {};
        }
        
        int n = encoded.size() + 1, val = 1;
        for(int i = 2; i <= n; ++ i) {
            val ^= i;
        }
        
        for(int i = 1; i < encoded.size(); i += 2) {
            val ^= encoded[i];
        }
        
        vector<int> ans(n, val);
        for(int i = 0; i < encoded.size(); ++ i) {
            ans[i + 1] = ans[i]^encoded[i];
        }
        return ans;
    }
};
