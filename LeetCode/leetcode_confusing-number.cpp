/*
*
* Tag: Math
* Time: O(lgn)
* Space: O(1)
*/

class Solution {
public:
    bool confusingNumber(int N) {
        long long rotatedN = 0, n = N;
        while(N > 0) {
            int v = N%10;
            if(v == 2 || v == 3 || v == 4 || v == 5 || v == 7) {
                return false;
            }
            if(v == 6) {
                v = 9;
            } else if(v == 9) {
                v = 6;
            }
            rotatedN = (rotatedN*10) + v;
            N /= 10;
        }
        
        return rotatedN != n;
    }
};
