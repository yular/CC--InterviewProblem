/*
*
* Tag: Greedy
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        if(sticks.size() == 0) {
            return 0;
        }
        
        priority_queue<int, vector<int>, greater<int>> pq(sticks.begin(), sticks.end());
        int ans = 0;
        while(pq.size() > 1) {
            int u = pq.top();
            pq.pop();
            int v = pq.top();
            pq.pop();
            int sum = u + v;
            ans += sum;
            pq.push(sum);
        }
        return ans;
    }
};
