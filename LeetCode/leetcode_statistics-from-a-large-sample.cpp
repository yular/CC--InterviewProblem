/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        if(count.size() == 0){
            return {};
        }
        
        int minVal = 255, maxVal = 0, mode = 0, maxCnt = 0, cntSum = 0;
        long long sum = 0;
        for(int i = 0; i < count.size(); ++ i) {
            if(count[i] == 0) {
                continue;
            }
            
            minVal = min(minVal, i);
            maxVal = max(maxVal, i);
            sum += i*count[i];
            if(count[i] > maxCnt) {
                maxCnt = count[i];
                mode = i;
            }
            cntSum += count[i];
        }
        
        int curCnt = 0, lastCnt = 0, lastNum = 0, curNum = 0;
        double median = 0.0;
        for(int i = 0; i < count.size(); ++ i){
            if(count[i] == 0) {
                continue;
            }
            
            lastNum = curNum;
            lastCnt = curCnt;
            curCnt += count[i];
            curNum = i;
            if(cntSum%2 == 1) {
                if(curCnt >= cntSum/2) {
                    median = i;
                    break;
                }
            } else {
                if(lastCnt == cntSum/2) {
                    cout<<lastNum<<" "<<curNum<<endl;
                    median = (double)(lastNum + curNum)/2.0;
                    break;
                } else if(lastCnt < cntSum/2 && curCnt >= cntSum/2 + 1) {
                    median = (double)curNum;
                    break;
                }
            }
        }
        
        vector<double> ans = {(double)minVal, (double)maxVal, (double)sum/cntSum, (double)median, (double)mode};
        return ans;
    }
};
