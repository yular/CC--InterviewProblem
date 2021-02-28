/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        if(6*nums1.size() < nums2.size() || 6*nums2.size() < nums1.size()) {
            return -1;
        }
        
        int sum1 = 0, sum2 = 0;
        vector<int> numCnt1(7, 0), numCnt2(7, 0);
        for(int num : nums1) {
            sum1 += num;
            ++ numCnt1[num];
        }
        for(int num : nums2) {
            sum2 += num;
            ++ numCnt2[num];
        }
        if(sum1 == sum2) {
            return 0;
        }
        if(sum1 > sum2) {
            swap(numCnt1, numCnt2);
        }
        
        int diff = abs(sum1 - sum2), ans = 0;
        for(int i = 1, j = 6; diff > 0;){
            while(numCnt1[i] == 0 && i < 6) {
                ++ i;
            }
            while(numCnt2[j] == 0 && j > 0) {
                -- j;
            }
            if(i > 6 || (j > 0 && j - 1 > 6 - i)) {
                diff -= (j - 1);
                -- numCnt2[j];
            } else {
                diff -= (6 - i);
                -- numCnt1[i];
            }
            ++ ans;
        }
        return ans;
    }
};
