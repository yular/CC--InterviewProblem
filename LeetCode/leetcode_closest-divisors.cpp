/*
*
* Tag: Math
* Time: O(sqrt(n))
* Space: O(1)
*/

class Solution {
public:
    vector<int> closestDivisors(int num) {
        if(num < 0) {
            return {};
        }
        
        for(int i = sqrt(num + 2); i > 0; -- i) {
            if((num + 1)%i == 0) {
                return {i, (num + 1)/i};
            }
            if((num + 2)%i == 0) {
                return {i, (num + 2)/i};
            }
        }
        return {};
    }
};
