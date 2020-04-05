/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    int countLargestGroup(int n) {
        if(n < 10) {
            return n;
        }
        
        int ans = 0, maxSumCnt = 0;
        unordered_map<int,int> sumCnt = {};
        for(int i = 1; i <= n; ++ i) {
            int sum = getDigitSum(i);
            ++ sumCnt[sum];
            if(sumCnt[sum] > maxSumCnt) {
                maxSumCnt = sumCnt[sum];
                ans = 1;
            } else if(sumCnt[sum] == maxSumCnt) {
                ++ ans;
            }
        }
        return ans;
    }
private:
    int getDigitSum(int v) {
        int sum = 0;
        while(v > 0) {
            sum += v%10;
            v /= 10;
        }
        return sum;
    }
};
