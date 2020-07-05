/*
*
* Tag: Greedy + fenwick tree
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
public:
    string minInteger(string num, int k) {
        if(k == 0) {
            return num;
        }
        
        int n = num.size(); 
        vector<int> fenwick(n + 1, 0);
        vector<queue<int>> numQue(10);
        for(int i = 0; i < n; ++ i) {
            updateTree(fenwick, i + 1, 1);
            numQue[num[i] - '0'].push(i);
        }
        
        string ans(n, '0');
        for(int i = 0; i < n; ++ i) {
            for(int j = 0; j < 10; ++ j) {
                if(numQue[j].empty()) {
                    continue;
                }
                
                int idx = numQue[j].front();
                int dis = sumUp(fenwick, idx);
                if(dis > k) {
                    continue;
                }
                
                updateTree(fenwick, idx + 1, -1);
                numQue[j].pop();
                ans[i] = j + '0';
                k -= dis;
                break;
            }
        }
        return ans;
    }
private:
    void updateTree(vector<int> &fenwick, int idx, int v) {
        for(int i = idx; i < fenwick.size(); i += lowbit(i)) {
            fenwick[i] += v;
        }
        return ;
    }
    
    int sumUp(vector<int> &fenwick, int idx) {
        int res = 0;
        for(int i = idx; i > 0; i -= lowbit(i)) {
            res += fenwick[i];
        }
        return res;
    }
    
    int lowbit(int x) {
        return x&-x;
    }
};
