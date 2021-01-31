/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        if(highLimit < lowLimit) {
            return 0;
        }
        
        int ans = 0;
        unordered_map<int,int> numCnt;
        for(int i = lowLimit; i <= highLimit; ++ i) {
            int v = getNumSum(i);
            ++ numCnt[v];
            ans = max(ans, numCnt[v]);
        }
        return ans;
    }
private:
    int getNumSum(int v) {
        int res = 0;
        while(v > 0) {
            res += v%10;
            v /= 10;
        }
        return res;
    }
};
