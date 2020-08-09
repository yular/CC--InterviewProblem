/*
*
* Tag: Bit Manipulation
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    int longestAwesome(string s) {
        if(s.size() < 2) {
            return s.size();
        }
        
        vector<int> stateIdx(2048, -1);
        vector<int> digitCnt(10, 0);
        unordered_set<int> powTwoSet= {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
        int ans = 0, state = 0;
        for(int i = 0; i < s.size(); ++ i) {
            int bit = s[i] - '0';
            state ^= (1<<bit);
            if(state == 0 || powTwoSet.count(state) > 0) {
                ans = max(ans, i + 1);
                if(stateIdx[state] == -1) {
                    stateIdx[state] = i;
                }
                continue;
            }
            
            for(int j = 0; j < 10; ++ j) {
                if(digitCnt[bit] == 0) {
                    continue;
                }
                             
                int mask = (1<<j);                
                int v = state^mask;                
                if(stateIdx[v] != -1) {
                    ans = max(ans, i - stateIdx[v]);
                }
            }
            
            if(stateIdx[state] == -1) {
                stateIdx[state] = i;
            }
            ++ digitCnt[bit];
        }
        return ans;
    }
};
