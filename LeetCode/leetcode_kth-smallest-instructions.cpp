/*
*
* Tag: Math
* Time: O((h+v)^2)
* Space: O(1)
*/

class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        if(k < 1 || destination.size() < 2) {
            return "";
        }
        
        int h = destination[1], v = destination[0], n = h + v;
        string ans = "";
        for(int i = 0; i < n; ++ i) {
            if(h > 0) {
                int cnt = getCombination(h + v - 1, v);
                if(k <= cnt) {
                    ans += 'H';
                    -- h;
                } else {
                    ans += 'V';
                    -- v;
                    k -= cnt;
                }
                continue;
            }
            
            ans += 'V';
            -- v;
        }
        return ans;
    }
private:
    int getCombination(int n, int r) {
        long long res = 1;
        for(int i = n - r + 1, j = 1; j <= r; ++ i, ++ j) {
            res = res*i/j;
        }
        return res;
    }
};
