/*
*
* Tag: Hash
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        if(s.size() < 2) {
            return 0;
        }
        
        vector<int> pos(26, -1);
        int ans = -1;
        for(int i = 0; i < s.size(); ++ i) {
            int idx = (s[i] - 'a');
            if(pos[idx] == -1) {
                pos[idx] = i; 
            } else {
                ans = max(ans, i - pos[idx] - 1);
            }
        }
        return ans;
    }
};
