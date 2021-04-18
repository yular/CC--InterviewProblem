/*
*
* Tag: Bit Manipulation
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        if(arr1.size() == 0 || arr2.size() == 0) {
            return 0;
        }
        
        vector<int> bitCnt(32, 0);
        for(int v : arr2) {
            long long mask = 1;
            for(int idx = 0; mask <= v; mask <<= 1, ++ idx) {
                if((v&mask) > 0) {
                    ++ bitCnt[idx];
                }
            }
        }
        
        int ans = 0;
        for(int v : arr1) {
            long long mask = 1, res = 0;
            for(int idx = 0; mask <= v; mask <<= 1, ++ idx) {
                if((v&mask) > 0 && (bitCnt[idx]&1) > 0) {
                    res |= mask;
                }
            }
            ans ^= res;
        }
        return ans;
    }
};
