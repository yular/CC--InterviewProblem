/*
*
* Tag: Data Structure
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    string reformat(string s) {
        if(s.size() == 0) {
            return s;
        }
        
        int n = s.size();
        queue<char> q[2];
        for(char c : s) {
            if(c >= '0' && c <= '9') {
                q[0].push(c);
            } else {
                q[1].push(c);
            }
        }
        if(abs((int)q[0].size() - (int)q[1].size()) > 1 ) {
            return "";
        }
        
        string ans = "";
        int idx = 0;
        if(q[1].size() > q[0].size()) {
            idx = 1;
        }
        
        while(ans.size() < n) {
            ans += q[idx].front();
            q[idx].pop();
            idx = (idx + 1)%2;
        }
        return ans.size() == n ? ans : "";
    }
};
