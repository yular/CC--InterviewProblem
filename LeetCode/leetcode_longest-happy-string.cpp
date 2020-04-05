/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(1)
*/

class Solution {
private:
    struct Node {
        char c;
        int val;
        bool operator < (const Node &a)const{
            return val < a.val;
        }
    };
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<Node> pq;
        Node node;
        if(a > 0) {
            node.c = 'a', node.val = a;
            pq.push(node);
        }
        if(b > 0) {
            node.c = 'b', node.val = b;
            pq.push(node);
        }
        if(c > 0) {
            node.c = 'c', node.val = c;
            pq.push(node);
        }
        
       string ans = "";
        while(!pq.empty()) {
            Node cur = pq.top();
            pq.pop();
            
            int n = cur.val, m = ans.size();
            if(ans.size() == 0 || ans[m - 1] != cur.c) {
                for(int i = 0; i < min(2, n); ++ i) {
                    ans += cur.c;
                    -- cur.val;
                }
                
                if(cur.val > 0) {
                    pq.push(cur);
                }
            } else {
                if(pq.empty()) {
                    break;
                }
                
                Node nxt = pq.top();
                pq.pop();
                
                ans += nxt.c;
                -- nxt.val;
                
                if(nxt.val > 0) {
                    pq.push(nxt);
                }
                pq.push(cur);
            }
        }
        return ans;
    }
};
