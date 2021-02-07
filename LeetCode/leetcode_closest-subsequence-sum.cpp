/*
*
* Tag: Divide and Conquer + Binary Search
* Time: O(2^n)
* Space: O(2^n)
*/

class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        if(n == 0) {
            return 0;
        }
        
		    vector<int> nums1(n/2, 0), nums2(n - n/2, 0);   
        for(int i = 0, idx = 0; i < n/2; ++ i) { 
            nums1[idx++] = nums[i];
        }
        for(int i = n/2, idx = 0; i < n; ++ i) {
            nums2[idx++] = nums[i];
        }
        
        vector<int> a = genSumSubset(nums1), b = genSumSubset(nums2);
        int res = INT_MAX;		
        for(int i = 0; i < a.size(); ++ i) {   
            int j = lower_bound(b.begin(), b.end(), goal - a[i]) - b.begin();
            if(j > 0) {
                res = min(res, abs(goal - b[j - 1] - a[i]));
            }
            if(j < b.size()) {
                res = min(res, abs(goal - b[j] - a[i]));
            }
        }
        return res;
    }
    
private:
    vector<int> genSumSubset(vector<int> &arr) {
        int n = arr.size();
        vector<int> res(1<<n, 0);
        for(int i = 0, idx = 0; i < (1<<n); ++ i, ++ idx) {
            int sum = 0;
            for(int j = 0; j < n; ++ j) {
                if((i&(1<<j)) > 0) {
                    sum += arr[j];
                }
            }
            res[idx] = sum;
        }
        sort(res.begin(), res.end());
        return res;
    }
};
