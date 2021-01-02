#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <set>
#include <string.h>
#include <vector>
using namespace std;

const int MOD = 1000000007;
typedef long long ll;

bool f(ll cnt, ll A, ll B, vector<ll> h, ll N) {
  vector<ll> tmp(N);
  for(int i = 0; i < N; i++) {
    tmp[i] = h[i] - cnt * B;
  }
  ll sum = 0LL;
  for(int i = 0; i < N; i++) {
    if(tmp[i] > 0)
      sum += (tmp[i] + (A - B - 1)) / (A - B);
  }
  if(sum <= cnt) {
    return true;
  } else {
    return false;
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll N, A, B;
  cin >> N >> A >> B;
  vector<ll> h(N);
  for(int i = 0; i < N; i++) {
    cin >> h[i];
  }

  ll sum = accumulate(h.begin(), h.end(), 0ll);

  ll ok = 2000000001ll;
  ll ng = -1ll;

  while(ok - ng > 1) {
    ll mid = (ok + ng) / 2;
    (f(mid, A, B, h, N) ? ok : ng) = mid;
  }

  cout << ok << endl;
}
