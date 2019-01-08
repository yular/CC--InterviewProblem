/*
*
* Tag: Math
* Time: O(n^1.5 * lgn)
* Space: O(1)
*/
class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c < 0){
            return false;
        }
        if(c == 0){
            return true;
        }
        int v = sqrt(c);
        if(v*v == c){
            return true;
        }
        for(long long i = 1; i*i <= c; ++ i){
            int res = c - i*i;
            v = sqrt(res);
            if(v*v == res) {
                return true;
            }
        }
        return false;
    }
};
