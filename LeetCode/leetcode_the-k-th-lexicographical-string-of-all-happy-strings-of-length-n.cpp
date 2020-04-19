/*
*
* Tag: DFS
* Time: O(2^n * lgk)
* Space: O(k)
*/

class Solution {
public:
    string getHappyString(int n, int k) {
        if(n <= 0 || k <= 0 || (3*(1<<(n - 1))) < k) {
            return "";
        }
        
        priority_queue<string> pq;
        
        dfs(pq, 0, n, k, "");
        
        return pq.size() >= k? pq.top() : "";
    }
private:
    void dfs(priority_queue<string> &pq, int len, int n, int k, string s) {
        if(len >= n) {
            pq.push(s);
            if(pq.size() > k) {
                pq.pop();
            }
            return ;
        }
        
        for(int i = 0; i < 3; ++ i) {
            char c = 'a' + i;
            string cur = s;
            if(s.size() > 0 && s[len - 1] == c) {
                continue;
            }
            cur += c;
            dfs(pq, len + 1, n, k, cur);
        }
        return ;
    }
};
