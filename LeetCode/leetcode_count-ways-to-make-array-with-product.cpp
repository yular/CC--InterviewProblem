/*
*
* Tag: Math
* Time: 
* Space:
* Credit: https://leetcode.com/problems/count-ways-to-make-array-with-product/discuss/1031066/c%2B%2B-Prime-Factorization-Stars-and-Bars-*Comments-and-Clear-Explanation*
*/

class Solution {
public:
  int spf[10001], mod = 1e9 + 7, MAXN = 10001;
  void sieve() {
    spf[1] = 1;  // spf[i] = smallest prime factor of i
    for (int i = 2; i < MAXN; i++) spf[i] = i;
    for (int i = 4; i < MAXN; i += 2) spf[i] = 2;
    for (int i = 3; i * i < MAXN; i++) {
      if (spf[i] == i) {                        // i is prime
        for (int j = i * i; j < 10001; j += i)  // mark all multiples of i
          if (spf[j] == j) spf[j] = i;
      }
    }
  }
  vector<int> get_factors(int x) {
    vector<int> res;
    unordered_map<int, int> frqs;  // a bit unnecessary but easier to code;
    while (x != 1) {
      frqs[spf[x]]++;  // frqs[i] = how many times the prime factor i occurs in x
      x = x / spf[x];
    }
    for (auto p : frqs) res.push_back(p.second);  // return the frequencies
    return res;
  }

  vector<int> waysToFillArray(vector<vector<int>>& queries) {
    vector<int> res;
    sieve();
    long choose[10050][33] = {0};                       // choose[i][j] = i Choose j
    for (int j = 0; j != 10050; ++j) choose[j][0] = 1;  // 1 way to choose 0 things
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
