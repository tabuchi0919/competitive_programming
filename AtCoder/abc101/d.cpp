#include <algorithm>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <string.h>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;

const int INF = (1 << 30) - 1;
const ll INFLL = (1LL << 61) - 1;
const int MOD = 1000000007;

ll digit_sum(ll num) {
  ll sum = 0, dig;
  while(num) {
    dig = num % 10;
    sum = sum + dig;
    num = num / 10;
  }
  return sum;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  vector<ll> res;
  ll base = 1;

  for(int i = 0; i < 15; ++i) {
    for(int j = 1; j < 150; ++j) {
      res.push_back(base * (j + 1) - 1);
    }
    base *= 10;
  }
  sort(res.begin(), res.end());
  res.erase(unique(res.begin(), res.end()), res.end());

  for(ll i = 0; i < res.size(); ++i) {
    for(ll j = i + 1; j < res.size(); ++j) {
      if((double)res[i] / digit_sum(res[i]) >
         (double)res[j] / digit_sum(res[j])) {
        res.erase(res.begin() + i--);
        break;
      }
    }
  }

  long long K;
  cin >> K;
  for(long long i = 0; i < K; ++i) {
    cout << res[i] << endl;
  }
}
