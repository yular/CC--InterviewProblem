/*
*
* Tag: Math + Greedy
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        if(maxSum <= n) {
            return 1;
        }
        
        maxSum -= n;
        int ans = 1;
        long long sum = 1, delta = 1;
        for(int i = 1; sum < maxSum; ++ i, ++ delta) {
            if(index > 0) {
                if(delta < index) {
                    sum += delta;
                } else {
                    sum += index;
                }
            }
            if(index < n - 1) {
                if(index + delta < n - 1) {
                    sum += delta;
                } else {
                    sum += (n - 1 - index);
                }
            }
            if(sum >= maxSum) {
                break;
            }
            ++ sum;
            ++ ans;
            if(sum < maxSum && delta >= index && index + delta >= n - 1){
                int diff = maxSum - sum;
                ans += diff/n;
                break;
            }
        }
        return ans + 1;
    }
};
