#include <algorithm>
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
  string s, t;
  vector<string> anss;
  cin >> s >> t;
  REP(i, int(s.length()) - int(t.length()) + 1) {
    string ss = s.substr(i, t.length());
    bool flag = true;
    string ans = s;
    REP(j, t.length()) {
      if(ss[j] != t[j] && ss[j] != '?') {
        flag = false;
      } else {
        ans[i + j] = t[j];
      }
    }
    if(flag) {
      REP(j, s.length()) {
        if(ans[j] == '?') {
          ans[j] = 'a';
        }
      }
      anss.push_back(ans);
    }
  }
  sort(ALL(anss));
  if(anss.size() == 0) {
    anss.push_back("UNRESTORABLE");
  }
  cout << anss[0] << endl;
}
