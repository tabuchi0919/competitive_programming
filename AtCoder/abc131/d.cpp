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
#define ALL(a) (a).begin(), (a).end()
#define rALL(a) (a).rbegin(), (a).rend()

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<pair<ll, ll>> BA(N);
  for(int i = 0; i < N; i++) {
    ll a, b;
    cin >> a >> b;
    BA[i] = make_pair(b, a);
  }
  sort(ALL(BA));
  ll sum = 0ll;
  bool flag = true;
  for(int i = 0; i < N; i++) {
    sum += BA[i].second;
    if(BA[i].first < sum) {
      flag = false;
    }
  }
  if(flag) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
