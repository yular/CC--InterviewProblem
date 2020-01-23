/*
*
* Tag: Binary Search
* Time: O(nlgn)
* Space: O(1)
*/
class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int K) {
        int ans = 0;
        if(sweetness.size() < K){
            return ans;
        }
        
        int sum = 0;
        for(int w : sweetness){
            sum += w;
        }
        
        int l = 1, r = K == 0? sum : sum/K;
        while(l <= r){
            int mid = (l + r)>>1;
            if(isValidCut(mid, K + 1, sweetness)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
    
private:
    bool isValidCut(int v, int k, vector<int>& sweetness) {
        int cnt = 0, sum = 0;
        for(int i = 0; i < sweetness.size(); ++ i){
            sum += sweetness[i];
            if(sum >= v) {
                ++ cnt;
                sum = 0;
            }
        }
        return cnt >= k;
    }
};
