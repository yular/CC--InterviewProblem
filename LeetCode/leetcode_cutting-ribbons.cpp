/*
*
* Tag: Binary Search
* Time: O(nlgm)
* Space: O(1)
*/

class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {
        if(k < 1) {
            return 0;
        }
        
        long long sum = 0, r = 0;
        for(int rib : ribbons) {
            sum += rib;
            r = max(r, (long long)rib);
        }
        if(sum < k) {
            return 0;
        }
        if(sum == k) {
            return 1;
        }
        
        long long l = 1, ans = 1;
        while(l <= r) {
            long long mid = (l + r)/2;
            if(isValid(mid, ribbons, k)) {
                ans = max(ans, mid);
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
private:
    bool isValid(long long len, vector<int>& ribbons, int k) {
        int cnt = 0;
        for(int rib : ribbons) {
            cnt += rib/len;
            if(cnt >= k) {
                return true;
            }
        }
        return false;
    }
};
