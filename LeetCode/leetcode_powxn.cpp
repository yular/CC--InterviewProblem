/*
* Algorithm: Brute force
* Time complexity: O(logn)
* Memory complexity: O(1)
*/
class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0) return 1.0;
        if(n == 1) return x;
        double ans = 1.0, xpow = x;
        int i = 0;
        bool flag = false;
        if(n < 0){
            n *= -1;
            flag = true;
        }
        while(1)
        {
            if(n<(1 << i) || i > 31) break;
            if(n & (1 << i)){
                ans *= xpow;
            }
            i ++;
            xpow *= xpow;
        }
        if(flag) ans = 1/ans;
        return ans;
    }
};
