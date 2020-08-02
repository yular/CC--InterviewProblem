/*
*
* Tag: Array, brute force
* Time: O(n)
* Space: O(n*k)
*/

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if(arr.size() == 0) {
            return 0;
        }
        if(k == 0) {
            return arr[0];
        }
        
        int maxVal = arr[0], n = arr.size();
        queue<int> q;
        q.push(arr[0]);
        for(int i = 1; i < n; ++ i) {
            maxVal = max(maxVal, arr[i]);
            q.push(arr[i]);
        }
        if(k >= n - 1) {
            return maxVal;
        }
        
        int cnt = 0, ans = 0;
        while(!q.empty()) {
            ans = q.front();
            q.pop();
            while(!q.empty() && cnt < k) {
                int cur = q.front();
                if(cur > ans) {
                    q.push(ans);
                    cnt = 1;
                    ans = cur;
                    break;
                }
                
                q.pop();
                q.push(cur);
                ++ cnt;
            }
            if(cnt >= k) {
                break;
            }
        }
        return ans;
    }
};
