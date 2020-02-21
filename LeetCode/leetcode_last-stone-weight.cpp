/*
*
* Tag: Priority Queue
* Time: O(nlgn)
* Space: O(n)
*/
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 0) {
            return 0;
        }
        
        priority_queue<int> pq;
        for(int stone : stones) {
            pq.push(stone);
        }
        
        while(pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if(x != y) {
                pq.push(abs(x - y));
            }
        }
        return pq.empty()? 0 : pq.top();
    }
};
