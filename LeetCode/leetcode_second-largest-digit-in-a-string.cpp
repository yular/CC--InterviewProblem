/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int secondHighest(string s) {
        if(s.size() < 2) {
            return -1;
        }
        
        vector<bool> vis(10, false);
        for(char c : s) {
            if(c < '0' || c > '9') {
                continue;
            }
            
            int idx = c - '0';
            vis[idx] = true;
        }
        
        int cnt = 0;
        for(int i = 9; i >= 0; -- i) {
            if(vis[i]) {
                ++ cnt;
            }
            if(cnt == 2) {
                return i;
            }
        }
        return -1;
    }
};
