#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

const int MOD = 1000000007, INF = 1111111111;
using namespace std;
typedef long long ll;

bool sortbysec(const pair<ll, ll> &a, const pair<ll, ll> &b) {
  return (a.second < b.second);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;

  vector<ll> A(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  vector<pair<ll, ll>> BC(M);
  for(int i = 0; i < M; i++) {
    ll b, c;
    cin >> b >> c;
    BC[i] = make_pair(b, c);
  }

  sort(A.begin(), A.end());
  sort(BC.rbegin(), BC.rend(), sortbysec);
  BC.push_back(make_pair(100000, 0));

  ll ans = 0ll;
  int now = 0, cnt = 0;
  for(int i = 0; i < N; i++) {
    if(BC[now].second > A[i]) {
      ans += BC[now].second;
    } else {
      ans += A[i];
    }
    cnt++;
    if(cnt >= BC[now].first) {
      now++;
      cnt = 0;
    }
  }
  cout << ans << endl;
}
