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
  int N;
  cin >> N;
  vector<int> field(289);
  REP(i, N) {
    string s;
    cin >> s;
    int l = stoi(s.substr(0, 4));
    int r = stoi(s.substr(5, 4));
    l = l / 100 * 60 + l % 100;
    r = r / 100 * 60 + r % 100;
    l -= l % 5;
    if(r % 5 != 0)
      r += (5 - r % 5);
    l /= 5;
    r /= 5;
    field[l]++;
    field[r]--;
  }

  int now = 0;
  bool raining = false;
  REP(i, 289) {
    now += field[i];
    if(now > 0 && !raining) {
      raining = true;
      cout << setfill('0') << right << setw(4);
      cout << i * 5 / 60 * 100 + i * 5 % 60 << '-';
    } else if(now == 0 && raining) {
      raining = false;
      int ii = i - 1;
      cout << setfill('0') << right << setw(4);
      cout << i * 5 / 60 * 100 + i * 5 % 60 << endl;
    }
  }
  if(raining)
    cout << 2400 << endl;
}
