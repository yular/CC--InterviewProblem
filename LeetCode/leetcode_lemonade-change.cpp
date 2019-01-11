/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if(bills.size() == 0){
            return true;
        }
        
        int numOfFives = 0, numOfTens = 0;
        for(int i = 0; i < bills.size(); ++ i){
            switch(bills[i]){
                case 5:
                    ++ numOfFives;
                    break;
                case 10:
                    if(numOfFives < 1){
                        return false;
                    }
                    -- numOfFives;
                    ++ numOfTens;
                    break;
                case 20:
                    if(numOfTens >= 1 && numOfFives >= 1){
                        -- numOfTens;
                        -- numOfFives;
                    } else if(numOfFives >= 3) {
                        numOfFives -= 3;
                    } else {
                        return false;
                    }
                    break;
            }
        }
        return true;
    }
};
