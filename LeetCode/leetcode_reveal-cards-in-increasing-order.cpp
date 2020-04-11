/*
*
* Tag: Queue
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        if(deck.size() == 0) {
            return {};
        }
        
        int n = deck.size();
        queue<int> q;
        for(int i = 0; i < n; ++ i) {
            q.push(i);
        }
        
        queue<int> ansQ;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            
            ansQ.push(cur);
            if(q.empty()) {
                break;
            }
            int nxt = q.front();
            q.pop();
            q.push(nxt);
        }
        
        sort(deck.begin(), deck.end());
        
        vector<int> ans(deck.size());
        int idx = 0;
        while(!ansQ.empty()) {
            int cur = ansQ.front();
            ansQ.pop();
            
            ans[cur] = deck[idx ++];
        }
        return ans;
    }
};
