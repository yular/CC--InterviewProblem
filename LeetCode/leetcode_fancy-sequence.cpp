/*
*
* Tag: Math // fermat's little theorem
* Time: O(1)
* Space: O(n)
*/

class Fancy {
private:
    int MOD = 1e9 + 7;
    vector<long long> seq;
    long long multi, increament, tot;
public:
    Fancy() {
        seq.resize(100010);
        tot = increament = 0;
        multi = 1;
    }
    
    void append(int val) {
        seq[tot ++] = (((val - increament + MOD)%MOD)*modInv(multi, MOD-2))%MOD;
    }
    
    void addAll(int inc) {
        increament = (increament + inc)%MOD;
    }
    
    void multAll(int m) {
        multi = (multi * m)%MOD;
        increament = (increament * m)%MOD;
    }
    
    int getIndex(int idx) {
        if(idx >= tot) {
            return -1;
        }
        return ((seq[idx]*multi)%MOD + increament)%MOD;
    }
private:
    long long modInv(long long v, long long p) {
        long long res = 1, fact = v;
        while(p > 0) {
            if((p&1) > 0) {
                res = (res*fact)%MOD;
            }
            
            fact = (fact*fact)%MOD;
            p >>= 1;
        }
        return res;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
