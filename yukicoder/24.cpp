#include <algorithm>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
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
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> a(N), b(N), c(N), d(N), r(N);
  REP(i, N) {
    string s;
    cin >> a[i] >> b[i] >> c[i] >> d[i] >> s;
    r[i] = (s == "YES");
  }
  FOR(i, 0, 10) {
    bool flag = true;
    REP(j, N) {
      if((i == a[j] || i == b[j] || i == c[j] || i == d[j]) != r[j])
        flag = false;
    }
    if(flag)
      cout << i << endl;
  }
}
