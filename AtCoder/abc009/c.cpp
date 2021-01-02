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

bool judge(string ans, string S, int K, int N) {
  int cnt = 0, n = ans.length();
  REP(i, n) { cnt += (ans[i] != S[i]); }
  // v1: まだ使っていないSの文字列 v2: Sの末尾
  vector<int> v1(26), v2(26);
  REP(i, N) v1[S[i] - 'a']++;
  REP(i, n) v1[ans[i] - 'a']--;
  FOR(i, n, N) v2[S[i] - 'a']++;
  int tmp = 0;
  REP(i, 26) { tmp += min(v2[i], v1[i]); }
  return cnt + (N - n - tmp) <= K;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int N, K;
  string S;
  cin >> N >> K >> S;
  vector<int> v1(26), v2(26);
  REP(i, N) v1[S[i] - 'a']++;
  string ans = "";
  REP(i, N) {
    REP(j, 26) {
      if(v1[j] == v2[j])
        continue;
      char c = j + 'a';
      string copy = ans;
      copy.push_back(c);
      if(judge(copy, S, K, N)) {
        ans.push_back(c);
        v2[j]++;
        break;
      }
    }
  }
  cout << ans << endl;
}
