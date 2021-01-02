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
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  string S, T;
  cin >> S >> T;
  int sn = S.length(), tn = T.length();
  vector<vector<ll>> table(26, vector<ll>(sn, -1));

  REP(i, 26) {
    REP(j, sn) {
      if(S[j] == i + 'a') {
        table[i][0] = j + 1;
        break;
      }
    }
  }

  REP(i, 26) {
    if(table[i][0] == -1)
      continue;
    FOR(j, 1, sn) {
      table[i][j] = table[i][j - 1] - 1;
      if(table[i][j] == 0) {
        FOR(k, j, sn) {
          if(S[k] == i + 'a') {
            table[i][j] = k - j + 1;
            break;
          }
        }
      }
      if(table[i][j] == 0) {
        table[i][j] = table[i][0] + sn - j;
      }
    }
  }

  // REP(i,26){
  //   cout<<(char)('a'+i)<<endl;
  //   REP(j,sn){
  //     cout<<table[i][j]<<endl;
  //   }
  // }

  ll ans = 0ll;
  REP(i, tn) {
    if(table[T[i] - 'a'][ans % sn] == -1) {
      ans = -1;
      break;
    }
    ans += table[T[i] - 'a'][ans % sn];
  }

  cout << ans << endl;
}
