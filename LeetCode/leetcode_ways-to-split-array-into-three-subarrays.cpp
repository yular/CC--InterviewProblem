/*
*
* Tag: Data Structure (ordered map) + Math
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
private:
    int MOD = 1e9 + 7;
public:
    int waysToSplit(vector<int>& nums) {
        if(nums.size() < 3) {
            return 0;
        }
        
        long long sum = 0, n = nums.size();
        vector<long long> presum(n, nums[0]);
        multimap<long long, int> sumDict;
        for(int i = 0; i < n; ++ i) {
            sum += nums[i];
            sumDict.insert (pair<long long,int>(sum, i));
            if(i >= 1) {
                presum[i] = presum[i - 1] + nums[i];
            }
        }
        long long ans = 0;
        if(sum == 0) {
            ans = (n-2)*(n-1)/2;
            return ans%MOD;
        }
        
        for(int i = 0; i < n - 2; ++ i){
            long long leftSum = presum[i];
            long long remain = sum - leftSum;
            if(remain < leftSum*2 || leftSum*3 > sum) {
                break;
            }
            
            long long doubleSum = 2*leftSum;
            auto it1 = sumDict.lower_bound(doubleSum);
            int idx1 = it1->second;
            if(leftSum == 0) {
                ++ idx1;
            }
            
            long long halfSum = leftSum + remain/2;
            auto it2 = sumDict.upper_bound(halfSum);
            it2 --;
            if(idx1 <= it2->second) {
                ans += (it2->second - idx1 + 1);
                ans %= MOD;
            }
        }
        return ans;
    }
};





/*
*
* Tag: Binary Search + Math
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
private:
    int MOD = 1e9 + 7;
public:
    int waysToSplit(vector<int>& nums) {
        if(nums.size() < 3) {
            return 0;
        }
        
        long long sum = nums[0], n = nums.size();
        vector<long long> presum(n, nums[0]);
        for (int i = 1; i < n; i++) {
            presum[i] = presum[i - 1] + nums[i];
            sum += nums[i];
        }
        long long ans = 0;
        if(sum == 0) {
            ans = (n-2)*(n-1)/2;
            return ans%MOD;
        }
        
        for (int i = 0; i < n - 2; ++ i) {
            int leftSum = presum[i];
            int remain = presum[n - 1] - leftSum;
            if (remain < leftSum * 2 || leftSum*3 > sum) {
                break;
            }
            int first = (int)(lower_bound(presum.begin() + i + 1,
                                          presum.end() - 1, leftSum * 2) -
                              presum.begin());
            int last =
                (int)(upper_bound(presum.begin() + i + 1, presum.end() - 1,
                                  leftSum + remain / 2) -
                      presum.begin() - 1);

            ans += max(last - first + 1, 0);
        }
        return ans % MOD;
    }
};
