/*
*
* Tag: Greedy
* Time: O(nlgn) + O((lgn)^2)
* Space: O(n)
*/

class Solution {
public:
    bool isPossible(vector<int>& target) {
        if(target.size() == 0){
            return false;
        }
        if(target.size() == 1) {
            return target[0] == 1;
        }
        
        //priority_queue<int,vector<int>, greater<int>> pq;
        priority_queue<int> pq;
        long long sum = 0;
        for(int v : target) {
            pq.push(v);
            sum += v;
        }
        
       while(pq.top() > 1) {
           int maxVal = pq.top();
           pq.pop();
           sum -= maxVal;
           if(maxVal < sum) {
               return false;
           }
           pq.push(maxVal - sum);
           sum = maxVal;
       }
        return true;
    }
};
