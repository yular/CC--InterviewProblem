/*
*
* Tag: Bit Manipulation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<int> dic;
        int tot = 1<<k, v = 0, mask = (1<<k) - 1;
        for(int i = 0; i < s.size(); ++ i) {
            int d = s[i] - '0';
            v <<= 1;
            v |= d;
            int res = (v & mask);
            if(i >= k - 1) {
                dic.insert(res);
                v = res;
            }
            
        }
        return dic.size() == tot;
    }
};
