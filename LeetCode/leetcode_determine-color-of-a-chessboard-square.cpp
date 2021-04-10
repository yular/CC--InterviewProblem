/*
*
* Tag: Implementation
* Time: O(1)
* Space: O(1)
*/

class Solution {
public:
    bool squareIsWhite(string coordinates) {
        if(coordinates.size() != 2) {
            return false;
        }
        
        int r = coordinates[1] - '1', c = coordinates[0] - 'a';
        if((c&1) == 0) {
            return (r&1) == 1;
        }
        return (r&1) == 0;
    }
};
