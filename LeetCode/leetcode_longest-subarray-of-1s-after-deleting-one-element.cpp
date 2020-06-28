/*
*
* Tag: Implementation or Greedy
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        
        int cnt = 0, ans = 0, cntOne = 0, n = nums.size();
        pair<int,int> prev = make_pair(-1, -1), cur = make_pair(-1, -1);
        for(int i = 0; i <= n; ++ i) {
            if(i == n || nums[i] == 0) {
                int v = 0;
                if(cur.first >= 0) {
                    v = cur.second - cur.first + 1;
                    ans = max(ans, v);
                }
                if(prev.second < 0) {
                    ans = max(ans, v);
                } else {
                    if(cur.first - prev.second == 2) {
                        ans = max(ans, prev.second - prev.first + 1 + v);
                    }
                }
                prev = cur;
                cur.first = cur.second = -1;
                continue;
            }
            if(cur.first < 0) {
                cur.first = i;
                ++ cnt;
            }
            cur.second = i;
            ++ cntOne;
        }
        if(cntOne == n) {
            return n - 1;
        }
        return ans;
    }
};
