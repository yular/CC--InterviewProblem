/*
*
* Tag: Sort + Hash
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        if(nums.size() < 2) {
            return nums;
        }
        
        unordered_map<int,int> numCnt;
        int n = nums.size();
        for(int i = 0; i < n; ++ i) {
            ++ numCnt[nums[i]];
        }
        
        vector<vector<int>> arr(numCnt.size(), vector<int>(2));
        int m = 0;
        for(auto it = numCnt.begin(); it != numCnt.end(); it ++) {
            arr[m ++] = {it->first, it->second};
        }
        
        sort(arr.begin(), arr.end(), cmp);
        
        vector<int> ans(n, 0);
        for(int i = 0, idx = 0; i < m; ++ i) {
            for(int j = 0; j < arr[i][1]; ++ j) {
                ans[idx ++] = arr[i][0];
            }
        }
        return ans;
    }
private:
    struct comparator {
        bool operator() (vector<int> &a, vector<int> &b) {
            return a[1] == b[1] ? a[0] > b[0] : a[1] < b[1];
        }
    }cmp;
};
