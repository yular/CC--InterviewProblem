/*
*
* Tag: Sliding Window
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        if(cardPoints.size() == 0) {
            return 0;
        }
        
        int n = cardPoints.size(), res = INT_MAX, len = n - k, tot = 0;
        for(int l = 0, r = 0, sum = 0; r < n; ++ r) {
            sum += cardPoints[r];
            tot += cardPoints[r];
            while(r - l + 1 > len) {
                sum -= cardPoints[l];
                ++ l;
            }
            if(r - l + 1 == len) {
                res = min(res, sum);
            }
        }
        return tot - res;
    }
};
