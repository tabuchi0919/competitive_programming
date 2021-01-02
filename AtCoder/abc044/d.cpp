#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

#define INF (1LL << 60)

typedef long long ll;

ll calc(ll b, ll n) {
  ll res = 0;
  if(b == 1)
    return n;
  while(n) {
    res += n % b;
    n /= b;
  }
  return res;
}

int main() {
  ll n, s;
  cin >> n >> s;

  ll ans = INF;
  if(n > s) {
    for(int i = sqrt(n); i >= 2; i--) {
      if(calc(i, n) == s)
        ans = min(ans, (ll)i);
    }
    for(int i = sqrt(n); i >= 1; i--) {
      ll b = (n - s) / i + 1;
      if(calc(b, n) == s)
        ans = min(ans, b);
    }
  } else {
    if(n == s)
      ans = n + 1;
  }
  if(ans == INF)
    ans = -1;
  cout << ans << endl;
  return 0;
}
