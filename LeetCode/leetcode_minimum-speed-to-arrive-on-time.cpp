/*
*
* Tag: Binary Search
* Time: O(nlgm)
* Space: O(n)
*/

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if(n - 1 >= hour) {
            return -1;
        }
        
        int ans = -1, l = 1, r = 1e8;
        while(l <= r) {
            int mid = (l + r)>>1;
            if(canReachDst(dist, mid, hour)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
    
private:
    bool canReachDst(vector<int>& dst, int v, double hour) {
        int tot = 0, n = dst.size();
        for(int i = 0; i < n; ++ i) {
            double t = (double)dst[i]/v;
            if(i < n - 1) {
                tot += (int)ceil(t);
                if(tot > hour) {
                    return false;
                }
                continue;
            }
            if(tot + t > hour) {
                return false;
            }
        }
        return true;
    }
};
