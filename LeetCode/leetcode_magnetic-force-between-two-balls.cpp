/*
*
* Tag: Binary Search
* Time: O(n*lgm) m is max(arr[0..n]) - min(arr[0..n])
* Space: O(1)
*/

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        if(m > position.size() || position.size() < 2) {
            return 0;
        }
        
        sort(position.begin(), position.end());
        
        int ans = 0, n = position.size();
        int l = 1, r = position[n - 1] - position[0];
        while(l <= r) {
            int mid = (l + r) >> 1;
            int v = getActualLen(position, mid, m);
            if(v == -1) {
                r = mid - 1;
            } else {
                ans = v;
                l = mid + 1;
            }
        }
        return ans;
    }
private:
    int getActualLen(vector<int>& position, int len, int m) {
        int cnt = 1, res = INT_MAX;
        for(int start = 0, i = 1; i < position.size(); ++ i) {
            if(position[i] - position[start] >= len) {
                res = min(res, position[i] - position[start]);
                start = i;
                ++ cnt;
            }
            if(cnt >= m) {
                return res;
            }
        }
        return -1;
    }
};
