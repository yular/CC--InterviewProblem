/*
*
* Tag: Sliding Window
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int minSwaps(vector<int>& data) {
        if(data.size() == 0) {
            return 0;
        }
        int cntOne = 0;
        for(int d : data) {
            cntOne += d;
        }
        if(cntOne < 2) {
            return 0;
        }
        
        int ans = cntOne, cnt = 0;
        for(int l = 0, r = 0; r < data.size(); ++ r) {
            cnt += data[r];
            if(r - l + 1 >= cntOne) {
                ans = min(ans, cntOne - cnt);
                cnt -= data[l];
                ++ l;
            }
        }
        return ans;
    }
};
