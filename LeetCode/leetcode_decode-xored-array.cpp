/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        if(encoded.size() == 0) {
            return {first};
        }
        
        int n = encoded.size();
        vector<int> ans(n + 1, first);
        for(int i = 0; i < n; ++ i) {
            ans[i + 1] = ans[i]^encoded[i];
        }
        return ans;
    }
};
