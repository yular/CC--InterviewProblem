/*
*
* Tag: Design, Math
* Time: O(n)
* Space: O(n)
*/

class RLEIterator {
private:
    vector<pair<int,int>> arr;
    int cur, idx;
public:
    RLEIterator(vector<int> A) {
        idx = 0;
        cur = 0;
        for(int i = 0; i < A.size(); i += 2) {
            arr.push_back(make_pair(A[i], A[i + 1]));
        }
        
        return ;
    }
    
    int next(int n) {
        int res = -1;
        while(n > 0 && idx < arr.size()) {
            res = arr[idx].second;
            if(cur + n >= arr[idx].first) {
                n -= (arr[idx].first - cur);
                cur = 0;
                ++ idx;
            } else {
                cur += n;
                n = 0;
            }
        }
        if(n > 0 && idx >= arr.size()) {
            res = -1;
        }
        return res;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */
