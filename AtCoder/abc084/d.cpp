#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <random>
#include <set>
#include <string.h>
#include <vector>

using namespace std;

const int MOD = 1000000007;
typedef long long ll;

std::vector<bool> IsPrime;

void sieve(size_t max) {
  if(max + 1 > IsPrime.size()) {
    IsPrime.resize(max + 1, true);
  }
  IsPrime[0] = false;
  IsPrime[1] = false;

  for(size_t i = 2; i * i <= max; ++i)
    if(IsPrime[i]) {
      for(size_t j = 2; i * j <= max; ++j) {
        IsPrime[i * j] = false;
      }
    }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int Q;
  cin >> Q;
  sieve(100000);
  vector<int> sum(100000, 0);
  for(int i = 3; i < 100000; i += 2) {
    if(IsPrime[i] && IsPrime[(i + 1) / 2]) {
      sum[i] = sum[i - 2] + 1;
    } else {
      sum[i] = sum[i - 2];
    }
  }
  for(int i = 0; i < Q; i++) {
    int r, l;
    cin >> l >> r;
    if(l == 1) {
      cout << sum[r] << endl;
    } else {
      cout << sum[r] - sum[l - 2] << endl;
    }
  }
}
