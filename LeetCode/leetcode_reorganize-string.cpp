/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(n)
*/

class Solution {
private:
    struct node {
        char c;
        int val;
        bool operator < (const node &a)const{
            return val < a.val;
        }
    };
public:
    string reorganizeString(string s) {
        if(s.size() == 0) {
            return "";
        }
        
        unordered_map<char,int> charCnt;
        for(char c : s) {
            ++ charCnt[c];
        }
        
        priority_queue<node> pq;
        for(auto it = charCnt.begin(); it != charCnt.end(); it ++) {
            node cur;
            cur.c = it->first, cur.val = it->second;
            pq.push(cur);
        }
        
        string ans = "";
        char lastChar = 0;
        while(!pq.empty()) {
            node cur = pq.top();
            pq.pop();
            
            if(lastChar == cur.c) {
                if(pq.empty()) {
                    return "";
                }
                
                node nxt = pq.top();
                pq.pop();
                ans += nxt.c;
                -- nxt.val;
                lastChar = nxt.c;
                
                pq.push(cur);
                if(nxt.val > 0) {
                    pq.push(nxt);
                }
                continue;
            }
            
            ans += cur.c;
            -- cur.val;
            lastChar = cur.c;
            if(cur.val == 0) {
                continue;
            }
            
            pq.push(cur);
        }
        return ans;
    }
};
