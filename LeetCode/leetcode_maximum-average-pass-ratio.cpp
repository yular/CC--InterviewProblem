/*
*
* Tag: Greedy + Heap
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
private:
    struct node {
        int p, tot;
        bool operator < (const node &a)const{
            double prInc = (double)(p + 1)/(double)(tot + 1) - (double)p/(double)tot;
            double prInc1 = (double)(a.p + 1)/(double)(a.tot + 1) - (double)a.p/(double)a.tot;
            return prInc < prInc1;
        }
    };
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        if(classes.size() == 0) {
            return 0;
        }
        
        int n = classes.size();
        priority_queue<node> pq;
        for(int i = 0; i < n; ++ i) {
            node nd;
            nd.p = classes[i][0], nd.tot = classes[i][1];
            pq.push(nd);
        }
        
        while(extraStudents > 0) {
            node nd = pq.top();
            pq.pop();
            ++ nd.p, ++ nd.tot;
            -- extraStudents;
            pq.push(nd);
        }
        
        double ans = 0;
        for(int i = 0; i < n; ++ i) {
            node nd = pq.top();
            pq.pop();
            ans += (double)nd.p/(double)nd.tot;
        }
        ans /= n;
        return ans;
    }
};
