/*
*
* Tag: BFS
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(start < 0 || start >= arr.size()) {
            return false;
        }
        if(arr[start] == 0) {
            return true;
        }
        
        vector<bool> vis(arr.size(), false);
        vector<int> q(arr.size(), 0);
        int front = 0, rear = 0;
        q[rear ++] = start;
        while(front < rear) {
            int cur = q[front ++];
            vis[cur] = true;
            vector<int> nxts = {cur - arr[cur], cur + arr[cur]};
            for(int nxt : nxts) {
                if(nxt < 0 || nxt >= arr.size() || vis[nxt]) {
                    continue;
                }
                if(arr[nxt] == 0) {
                    return true;
                }
                vis[nxt] = true;
                q[rear ++] = nxt;
            }
        }
        return false;
    }
};
