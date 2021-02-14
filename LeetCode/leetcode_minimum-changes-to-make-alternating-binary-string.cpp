/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int minOperations(string s) {
        if(s.size() < 2) {
            return 0;
        }
        
        int ans = 0, n = s.size(), cnt = 0;
        for(int i = 0; i < n; ++ i) {
            if(i%2 == 0) {
                cnt += s[i] == '0' ? 0 : 1;
            } else {
                cnt += s[i] == '1' ? 0 : 1;
            }
        }
        ans = min(n, cnt);
        cnt = 0;
        for(int i = 0; i < n; ++ i) {
            if(i%2 == 0) {
                cnt += s[i] == '1' ? 0 : 1;
            } else {
                cnt += s[i] == '0' ? 0 : 1;
            }
        }
        return min(ans, cnt);
    }
};
