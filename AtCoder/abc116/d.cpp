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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, K;
  ll sum = 0ll, ans = 0ll, tmp;
  cin >> N >> K;
  vector<ll> d(N), t(N), f(N, -1000000ll);
  for(int i = 0; i < N; i++) {
    cin >> t[i] >> d[i];
    f[t[i] - 1] = max(f[t[i] - 1], d[i]);
  }

  multiset<ll> se;

  sort(d.rbegin(), d.rend());
  sort(f.rbegin(), f.rend());

  for(int i = 0; i < K; i++) {
    sum += d[i];
    se.insert(d[i]);
  }

  tmp = sum;

  for(ll i = 1ll; i <= K; i++) {
    ll add = f[i - 1];
    ll back = *se.begin();
    tmp += add;
    if(back > add) {
      se.erase(se.begin());
      tmp -= back;
    } else {
      se.erase(se.find(add));
      tmp -= add;
    }

    ans = max(ans, tmp + i * i);
  }

  cout << ans << endl;
}
