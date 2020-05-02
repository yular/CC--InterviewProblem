/*
*
* Tag: Hash + Bit Manipulation
* Time: O(min(n, 2^8))
* Space: O(1)
*/

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        if(N == 0) {
            return cells;
        }
        
        unordered_map<int, int> numStep, stepNum;
        int step = 0, num = convertToInt(cells);
        
        stepNum[step] = num;
        numStep[num] = step ++;
        vector<int> cur = cells;
        
        for(int i = 0; i < N; ++ i, ++ step) {
            vector<int> nxt(8, 0);
            for(int j = 1; j < 7; ++ j) {
                if(cur[j - 1] == cur[j + 1]) {
                    nxt[j] = 1;
                }
            }
            
            num = convertToInt(nxt);
            if(numStep.count(num) > 0) {
                int len = (N - numStep[num])%(step - numStep[num]);
                int idx = numStep[num] + len;
                cur = convertToVec(stepNum[idx]);
                break;
            }
            
            stepNum[step] = num;
            numStep[num] = step;
            cur = nxt;
        }
        
        return cur;
    }
private:
    int convertToInt(vector<int>& cells) {
        int res = 0, mask = 1;
        for(int i = 0; i < 8; ++ i, mask <<= 1) {
            if(cells[i] == 0) {
                continue;
            }
            
            res |= mask;
        }
        return res;
    }
    
    vector<int> convertToVec(int num) {
        vector<int> res(8, 0);
        int mask = 1;
        for(int i = 0; i < 8; ++ i, mask <<= 1) {
            if((num&mask) == 0) {
                continue;
            }
            
            res[i] = 1;
        }
        return res;
    }
};
