/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    string maxValue(string n, int x) {
        if(n.size() == 0) {
            return n;
        }
        
        string ans = "";
        if(n[0] == '-') {
            ans = "-";
            for(int i = 1; i < n.size(); ++ i) {
                int v = n[i] - '0';
                if(v > x) {
                    ans += to_string(x);
                    ans += n.substr(i);
                    return ans;
                }
                ans += n[i];
            }
            n += to_string(x);
            return n;
        }
        
        for(int i = 0; i < n.size(); ++ i) {
            int v = n[i] - '0';
            if(v < x) {
                ans += to_string(x);
                ans += n.substr(i);
                return ans;
            }
            ans += n[i];
        }
        n += to_string(x);
        return n;
    }
};
