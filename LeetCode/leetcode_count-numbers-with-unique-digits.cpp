/*
*
* Tag: DP
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        init();
        return n <= 10? dp[n]:dp[10];
    }
private:
    void init(){
        dp.resize(11);
        dp[0] = 1;
        dp[1] = 10;
        int fact = 9, res = 1;
        for(int i = 9, j = 2; i >= 1; -- i, ++ j){
            res *= i;
            dp[j] = dp[j - 1] + fact*res;
        }
    }
private:
    vector<int> dp;
};
