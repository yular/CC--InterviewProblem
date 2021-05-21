/*
*
* Tag: implementation
* Time: O(n^0.5)
* Space: O(1)
*/

class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        if(memory1 <= 0 && memory2 <= 0) {
            return {1, 0, 0};
        }
        
        int t = 1;
        for(int i = 1; i <= memory1 || i <= memory2; ++ i) {
            if(memory1 >= memory2) {
                memory1 -= i;
            } else {
                memory2 -= i;
            }
            ++ t;
        }
        
        return {t, memory1, memory2};
    }
};
