/*
*
* Tag: Sliding Window + Heap (Data Structure)
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
private:
    struct node {
        int id, val;
        bool operator < (const node &a)const{
            return val < a.val;
        }
    };
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        if(k < 1 || points.size() < 2) {
            return 0;
        }
        
        node nd;
        nd.id = points[0][0], nd.val = points[0][1] - points[0][0];
        
        priority_queue<node> pq;
        pq.push(nd);
        
        int ans = INT_MIN;
        for(int i = 1; i < points.size(); ++ i) {
            int v = points[i][1] + points[i][0];
            while(!pq.empty() && points[i][0] - pq.top().id > k) {
                pq.pop();
            }
            
            if(!pq.empty()) {
                ans = max(ans, pq.top().val + v);
            }
            node nd;
            nd.id = points[i][0], nd.val = points[i][1] - points[i][0];
            pq.push(nd);
        }
        return ans;
    }
};
