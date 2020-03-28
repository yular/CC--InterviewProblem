/*
*
* Tag: Sort, Order Statistics
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    int getKth(int lo, int hi, int k) {
        if(lo > hi || k == 0) {
            return -1;
        }
        
        vector<pair<int,int>> arr(hi - lo + 1);
        int idx = 0;
        for(int i = lo; i <= hi; ++ i, ++ idx) {
            arr[idx] = make_pair(i, getPowerOf(i));
        }
        
        return getKthVal(arr, k);
    }
private:
    int getPowerOf(int v) {
        int cnt = 0;
        while(v > 1) {
            if((v&1) == 0) {
                v >>= 1;
            } else {
                v = 3*v + 1;
            }
            ++ cnt;
        }
        
        return cnt;
    }
    
    int getKthVal(vector<pair<int,int>> &nums, int k ) {
        pair<int,int> ans;
        int n = nums.size() - 1, start = 0, end = nums.size() - 1;
        
        while( 1 ) {
            pair<int,int> pivot = nums[end];
            int tpos = start - 1;
            
            for( int i = start; i < end; ++ i ){
                if( nums[i].second < pivot.second || (nums[i].second == pivot.second && nums[i].first < pivot.first) ){
                    swap( nums[i], nums[++tpos] );
                }
            }
            
            swap(nums[++ tpos], nums[end]);
            if( tpos == k - 1){
                ans = nums[tpos];
                break;
            }else if( tpos > k - 1 ){
                end = tpos - 1;
            }else{
                start = tpos + 1;
            }
        }
        
        return ans.first;
    }
};
