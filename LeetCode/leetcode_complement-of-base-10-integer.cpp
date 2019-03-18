/*
*
* Tag: Bit Manipulation
* Time: O(lgn)
* Space: O(1)
*/
class Solution {
public:
    int bitwiseComplement(int N) {
        if(N == 0){
            return 1;
        }
        
        long long mask = 1;
        while(mask <= N){
            N ^= mask;
            mask <<= 1;
        }
        return N;
    }
};
