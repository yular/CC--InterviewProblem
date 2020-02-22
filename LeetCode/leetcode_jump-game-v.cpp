/*
*
* Tag: DP
* Time: O(nlgn) + O(nd)
* Space: O()
*/

class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        if(d == 0){
            return 0;
        }
        if(arr.size() == 1) {
            return 1;
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
        for(int i = 0; i < arr.size(); ++ i) {
            pq.push(make_pair(arr[i], i));
        }
        
        int ans = 0;
        vector<int> dp(arr.size(), 1);
        while(!pq.empty()) {
            pair<int,int> cur = pq.top();
            pq.pop();
            
            int height = cur.first, idx = cur.second;
            bool canMoveLeft = true, canMoveRight = true;
            for(int i = 1; i <= d && (canMoveLeft || canMoveRight); ++ i) {
                if(idx - i >= 0 && canMoveLeft) {
                    if(arr[idx - i] >= height) {
                        canMoveLeft = false;
                    }
                    if(canMoveLeft) {
                        dp[idx] = max(dp[idx], dp[idx - i] + 1);
                    }
                }
                if(idx + i < arr.size() && canMoveRight) {
                    if(arr[idx + i] >= height) {
                        canMoveRight = false;
                    }
                    if(canMoveRight) {
                        dp[idx] = max(dp[idx], dp[idx + i] + 1);   
                    }
                }
            }
            ans = max(ans, dp[idx]);
        }
        
        return ans;
    }

private:
    struct cmp{
        bool operator () (const pair<int,int> &a, const pair<int,int> &b) {
            return b.first < a.first;
        }
    };
};
