/*
*
* Tag: Greedy
* Time: O(lgn)
* Space: O(1)
*/

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        if(numBottles == 0 || numExchange == 0) {
            return 0;
        }
        
        int ans = 0, numFullBottles = numBottles, numEmptyBottles = 0;
        while(numFullBottles > 0) {
            ans += numFullBottles;
            numEmptyBottles += numFullBottles;
            numFullBottles = numEmptyBottles/numExchange;
            numEmptyBottles %= numExchange;
        }
        return ans;
    }
};

/*
*
* Tag: Math
* Time: O(1)
* Space: O(1)
*/

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        if(numBottles == 0 || numExchange < 2) {
            return 0;
        }
        
        return numBottles + (numBottles-1) / (numExchange-1);
    }
};
