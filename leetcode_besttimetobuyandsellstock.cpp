/*
* Algorithm: DP
* Time complexity: O(n)
* Memory complexity: O(1)
*/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int ans = -1*(1<<29);
        int sum = 0;
        for(int i = 1; i < prices.size(); i ++){
            int val = prices[i] - prices[i - 1];
            if(val >= 0){
                sum += val;
                ans = max(ans, sum);
            }else{
                if(sum + val >= 0){
                    sum += val;
                    ans = max(ans, sum);
                }else
                    sum = 0;
            }
        }
        ans = max(sum, ans);
        return ans;
    }
};
