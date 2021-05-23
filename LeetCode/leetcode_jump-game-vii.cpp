/*
*
* Tag: Data Structure (set)
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if(s.size() == 0 || s[0] == '1') {
            return false;
        }
        
        set<int> pos;
        pos.insert(0);
        int n = s.size(), curMax = 0;
        for(int i = 1; i < n; ++ i) {
            if(s[i] == '1') {
                continue;
            }
            
            int prev = i - maxJump;
            if(prev > curMax) {
                continue;
            }
            
            auto it = pos.lower_bound(prev);
            if(it == pos.end() || *it > i - minJump) {
                continue;
            }
            pos.insert(i);
            curMax = max(curMax, i);
        }
        return pos.count(n - 1);
    }
};
