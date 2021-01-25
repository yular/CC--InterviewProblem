/*
*
* Tag: Math
* Time: 
* Space:
* Credit: https://leetcode.com/problems/count-ways-to-make-array-with-product/discuss/1031066/c%2B%2B-Prime-Factorization-Stars-and-Bars-*Comments-and-Clear-Explanation*
*/

class Solution {
private:
  int primes[10001], mod = 1e9 + 7, MAXN = 10001;
    
  void sieve() {
    primes[1] = 1; 
    for (int i = 2; i < MAXN; i++) primes[i] = i;
    for (int i = 4; i < MAXN; i += 2) primes[i] = 2;
    for (int i = 3; i * i < MAXN; i++) {
      if (primes[i] == i) {                        // i is prime
        for (int j = i * i; j < 10001; j += i)  // mark all multiples of i
          if (primes[j] == j) primes[j] = i;
      }
    }
  }
  vector<int> get_factors(int x) {
    vector<int> res;
    unordered_map<int, int> frqs;  // a bit unnecessary but easier to code;
    while (x != 1) {
      frqs[primes[x]]++;
      x = x / primes[x];
    }
    for (auto p : frqs) res.push_back(p.second);  // return the frequencies
    return res;
  }
    
public:
  vector<int> waysToFillArray(vector<vector<int>>& queries) {
      if(queries.size() == 0) {
          return {};
      }
      
      vector<int> res;
      sieve();
      
      long choose[10050][33] = {0};
      for (int j = 0; j != 10050; ++j) choose[j][0] = 1;
      for (int n = 1; n != 10050; ++n) {
          for (int r = 1; r != 33; ++r) {
            choose[n][r] = (choose[n - 1][r - 1] + choose[n - 1][r]) % mod;
          }
      }
      
      for (auto& q : queries) {
          int n = q[0], k = q[1];
          auto frqs = get_factors(k);
          long curr = 1;
          for (int f : frqs) {
            curr = (curr * choose[n + f - 1][f]) % mod;
          }
          res.push_back(curr);
      }
      return res;
  }
};
