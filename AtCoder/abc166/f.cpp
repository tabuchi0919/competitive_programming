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
  ll N, A, B, C;
  cin >> N >> A >> B >> C;
  vector<string> ss(N + 1);
  REP(i, N) cin >> ss[i];
  ss[N] = "AB";

  bool ans = true;

  vector<char> anss;
  anss.reserve(N);

  if(A + B + C == 0) {
    ans = false;
  } else if(A + B + C == 1) {
    REP(i, N) {
      if(ss[i] == "AB") {
        if(A > 0) {
          anss.push_back('B');
          A--;
          B++;
        } else if(B > 0) {
          anss.push_back('A');
          B--;
          A++;
        } else {
          ans = false;
        }
      } else if(ss[i] == "AC") {
        if(A > 0) {
          anss.push_back('C');
          A--;
          C++;
        } else if(C > 0) {
          anss.push_back('A');
          C--;
          A++;
        } else {
          ans = false;
        }
      } else {
        if(C > 0) {
          anss.push_back('B');
          C--;
          B++;
        } else if(B > 0) {
          anss.push_back('C');
          B--;
          C++;
        } else {
          ans = false;
        }
      }
      if(!ans)
        break;
    }
  } else {
    if(A + B + C == max({A, B, C})) {
      if(A > 0 && ss[0] == "BC") {
        ans = false;
      } else if(B > 0 && ss[0] == "AC") {
        ans = false;
      } else if(C > 0 && ss[0] == "AB") {
        ans = false;
      }
    }
    // ここからは絶対構築可能
    REP(i, N) {
      if(ss[i] == "AB") {
        if(A == 1 && B == 1) {
          //先読み
          if(ss[i + 1] == "AB") {
            //どちらでも良い
            anss.push_back('B');
            A--;
            B++;
          } else if(ss[i + 1] == "BC") {
            anss.push_back('B');
            A--;
            B++;
          } else {
            anss.push_back('A');
            B--;
            A++;
          }
        } else if(A + B == 1) {
          //なすがまま
          if(A > 0) {
            anss.push_back('B');
            A--;
            B++;
          } else if(B > 0) {
            anss.push_back('A');
            B--;
            A++;
          }
        } else {
          if(A >= 2) {
            anss.push_back('B');
            A--;
            B++;
          } else {
            anss.push_back('A');
            B--;
            A++;
          }
        }
      } else if(ss[i] == "AC") {
        if(A == 1 && C == 1) {
          //先読み
          if(ss[i + 1] == "AC") {
            //どちらでも良い
            anss.push_back('C');
            A--;
            C++;
          } else if(ss[i + 1] == "BC") {
            anss.push_back('C');
            A--;
            C++;
          } else {
            anss.push_back('A');
            C--;
            A++;
          }
        } else if(A + C == 1) {
          //なすがまま
          if(A > 0) {
            anss.push_back('C');
            A--;
            C++;
          } else if(C > 0) {
            anss.push_back('A');
            C--;
            A++;
          }
        } else {
          if(A >= 2) {
            anss.push_back('C');
            A--;
            C++;
          } else {
            anss.push_back('A');
            C--;
            A++;
          }
        }
      } else {
        if(B == 1 && C == 1) {
          //先読み
          if(ss[i + 1] == "BC") {
            //どちらでも良い
            anss.push_back('C');
            B--;
            C++;
          } else if(ss[i + 1] == "AC") {
            anss.push_back('C');
            B--;
            C++;
          } else {
            anss.push_back('B');
            C--;
            B++;
          }
        } else if(B + C == 1) {
          //なすがまま
          if(B > 0) {
            anss.push_back('C');
            B--;
            C++;
          } else if(C > 0) {
            anss.push_back('B');
            C--;
            B++;
          }
        } else {
          if(B >= 2) {
            anss.push_back('C');
            B--;
            C++;
          } else {
            anss.push_back('B');
            C--;
            B++;
          }
        }
      }
    }
  }

  if(ans) {
    cout << "Yes" << endl;
    REP(i, N) cout << anss[i] << endl;
  } else {
    cout << "No" << endl;
  }
}
