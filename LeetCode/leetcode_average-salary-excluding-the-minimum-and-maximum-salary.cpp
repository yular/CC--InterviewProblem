/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    double average(vector<int>& salary) {
        if(salary.size() < 3) {
            return 0;
        }
        
        int minVal = salary[0], maxVal = salary[0], sum = 0, n = salary.size();
        for(int v : salary) {
            minVal = min(minVal, v);
            maxVal = max(maxVal, v);
            sum += v;
        }
        return (sum - minVal - maxVal)/(double)(n - 2);
    }
};
