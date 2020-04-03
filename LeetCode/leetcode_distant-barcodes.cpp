/*
*
* Tag: Greedy
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
private:
    struct Node {
        int v, cnt;
        bool operator < (const Node &a)const{
            return cnt < a.cnt;
        }
    };
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        if(barcodes.size() == 0) {
            return {};
        }
        
        unordered_map<int,int> numCnt;
        for(int barcode : barcodes) {
            ++ numCnt[barcode];
        }
        
        priority_queue<Node> pq;
        for(pair<int,int> num : numCnt) {
            Node node;
            node.v = num.first, node.cnt = num.second;
            pq.push(node);
        }
        
        vector<int> ans(barcodes.size());
        int idx = 0;
        while(!pq.empty()) {
            Node cur = pq.top();
            pq.pop();
            
            if(idx == 0 || ans[idx - 1] != cur.v) {
                ans[idx ++] = cur.v;
                -- cur.cnt;
            } else {
                if(pq.empty()) {
                    return {};
                }
                
                Node nxt = pq.top();
                pq.pop();
                
                ans[idx ++] = nxt.v;
                -- nxt.cnt;
                
                if(nxt.cnt > 0) {
                    pq.push(nxt);
                }
            }
            
            if(cur.cnt > 0) {
                pq.push(cur);
            }
        }
        return ans;
    }
};
