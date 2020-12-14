/*
*
* Tag: DP + Sliding Window
* Time: O(n)
* Space: O(n)
* Credit: https://leetcode.com/problems/delivering-boxes-from-storage-to-ports/discuss/969723/JavaC%2B%2BPython-Sliding-Window-O(N)-Solution
*/

class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        int n = boxes.size(), need = 0, j = 0, lastj = 0;
        vector<int> dp(n + 1, 200000);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            while (j < n && maxBoxes > 0 && maxWeight >= boxes[j][1]) {
                maxBoxes -= 1;
                maxWeight -= boxes[j][1];
                if (j == 0 || boxes[j][0] != boxes[j - 1][0]) {
                    lastj = j;
                    need++;
                }
                j++;
            }
            dp[j] = min(dp[j], dp[i] + need + 1);
            dp[lastj] = min(dp[lastj], dp[i] + need);
            maxBoxes += 1;
            maxWeight += boxes[i][1];
            if (i == n - 1 || boxes[i][0] != boxes[i + 1][0]) {
                need--;
            }
        }
        return dp[n];
    }
};
