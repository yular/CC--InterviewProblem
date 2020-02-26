/*
*
* Tag: Design, Cache
* Time: O(1)
* Space: O(1)
*/

class ProductOfNumbers {
private:
    vector<int> q;
    int curIdx, lastZeroIdx, qIdx;
public:
    ProductOfNumbers() {
        q.resize(50000);
        curIdx = 0;
        qIdx = 0;
        lastZeroIdx = -1;
    }
    
    void add(int num) {
        curIdx ++;
        if(num == 0) {
            lastZeroIdx = curIdx - 1;
            qIdx = 0;
            return ;
        }
        int v = num;
        if(qIdx > 0) {
            v *= q[qIdx - 1];
        }
        q[qIdx ++] = v;
    }
    
    int getProduct(int k) {
        if(lastZeroIdx == -1 || lastZeroIdx + k + 1 <= curIdx) {
            int ans = q[qIdx - 1];
            return qIdx == k? ans : ans/q[qIdx - k - 1];
        }
        return 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
