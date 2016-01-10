/*
*
* Tag: Math
* Time: O(lgn)
* Space: O(1)
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n <= 0? false : log10(n)/log10(2) == floor(log10(n)/log10(2));
    }
};

/*
*
* Tag: Math & Bit Manipulation
* Time: O(lgn)
* Space: O(1)
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;
        int cnt_one = 0;
        while(n){
            if(n&1)
                ++ cnt_one;
            if(cnt_one > 1)
                return false;
            n>>=1;
        }
        return true;
    }
};
