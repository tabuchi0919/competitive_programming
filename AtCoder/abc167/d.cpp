#include <algorithm>
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
typedef long long ll;

template <class T> inline bool chmin(T &a, T b) {
  if(a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T> inline bool chmax(T &a, T b) {
  if(a < b) {
    a = b;
    return true;
  }
  return false;
}

const int INF = (1 << 30) - 1;
const ll INFLL = (1LL << 61) - 1;
const int MOD = 1000000007;
#define ALL(a) (a).begin(), (a).end()
#define rALL(a) (a).rbegin(), (a).rend()
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N);
  REP(i, N) {
    cin >> A[i];
    A[i]--;
  }
  vector<ll> last(N, -1);
  last[0] = 0;
  ll now = 0;
  ll nokori = K;
  ll cnt = 0;
  while(true) {
    nokori--;
    cnt++;
    ll next = A[now];
    if(last[next] == -1) {
      last[next] = cnt;
      now = next;
    } else {
      ll loop = cnt - last[next];
      now = next;
      nokori %= loop;
      break;
    }
    if(nokori == 0)
      break;
  }
  REP(i, nokori) {
    ll next = A[now];
    now = next;
  }

  cout << now + 1 << endl;
}
