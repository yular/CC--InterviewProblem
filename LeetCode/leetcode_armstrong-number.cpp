/*
*
* Tag: Math
* Time: O(nlgn) where n is the number of digits of given integer
* Space: O(1)
*/
class Solution {
public:
    bool isArmstrong(int N) {
        string str = to_string(N);
        int p = str.size();
        int sum = 0;
        for(char v : str){
            sum += fastPow((v - '0'), p);
            if(sum > N) {
                return false;
            }
        }
        return sum == N;
    }
private:
    int fastPow(int x, int p) {
        long long res = 1, fac = x;
        for(int i = 1; i <= p; i <<= 1) {
            if((i&p) > 0){
                res *= fac;
            }
            fac *= fac;
        }
        return res;
    }
};
