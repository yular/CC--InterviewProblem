/*
*
* Tag: Hash + Bit Manipulation
* Time: O(n)
* Space: O(m) where m is the given integer N
*/

class Solution {
public:
    bool queryString(string S, int N) {
        if(S.size() == 0) {
            return false;
        }
        
        unordered_set<int> visNum;
        int numOfNotFoundNum = N;
        for(int i = S.size() - 1; i >= 0 && numOfNotFoundNum > 0; -- i){
            long long val = 0, mask = 1;
            for(int j = i; j >= 0 && (val|mask) <= N && mask <= N && numOfNotFoundNum > 0; -- j){
                if(S[j] == '1') {
                    val |= mask;
                }
                if(visNum.count(val) == 0 && val > 0) {
                    visNum.insert(val);
                    -- numOfNotFoundNum;
                }
                mask <<= 1;
            }
        }
        
        return numOfNotFoundNum == 0;
    }
};
