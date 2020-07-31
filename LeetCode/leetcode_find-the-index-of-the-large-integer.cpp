/*
*
* Tag: Binary Search
* Time: O(lgn) assume array operation is O(1) 
* Space: O(1)
*/

/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y] 
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     int compareSub(int l, int r, int x, int y);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    int getIndex(ArrayReader &reader) {
        int len = reader.length();
        if(len < 2) {
            return 0;
        }
        
        int l = 0;
        while(len >= 1) {
            if(len == 1) {
                return l;
            }
            
            int mid = l + len/2;
            int r = l + len/2 - 1, x = mid, y = l + len - 1;
            if((len&1) == 1) {
                ++ x;
            }
            
            int v = reader.compareSub(l, r, x, y);
            if((len&1) == 1) {
                if(v == 0) {
                    return mid;
                }
                if(v < 0) {
                    l = mid + 1;
                }
            } else {
                if(v < 0) {
                    l = mid;
                }
            }
            len >>= 1;
        }
        return 0;
    }
};
