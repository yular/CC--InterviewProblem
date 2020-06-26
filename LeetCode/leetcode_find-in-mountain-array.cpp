/*
*
* Tag: Binary Search
* Time: O(ngln)
* Space: O(1)
*/

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int l = 1, r = mountainArr.length() - 2, peak = -1;
        while(l <= r) {
            int mid = (l + r)>>1;
            int v = mountainArr.get(mid), left = mountainArr.get(mid - 1), right = mountainArr.get(mid + 1);
            if(v > left && v > right) {
                peak = mid;
                break;
            } else if(v > left && v < right) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        int v = mountainArr.get(peak);
        if(v == target) {
            return peak;
        } else if(v < target) {
            return -1;
        }
        
        l = 0, r = peak;
        while(l <= r) {
            int mid = (l + r)>>1;
            int v = mountainArr.get(mid);
            if(v == target) {
                return mid;
            } else if(v < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        l = peak + 1, r = mountainArr.length() - 1;
        while(l <= r) {
            int mid = (l + r)>>1;
            int v = mountainArr.get(mid);
            if(v == target) {
                return mid;
            } else if(v < target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }
};
