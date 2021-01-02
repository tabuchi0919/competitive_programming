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
  int H, W;
  cin >> H >> W;
  vector<string> S(H + 2);
  S[0] = S[H + 1] = '.' * (W + 2);
  for(int i = 1; i < H + 1; i++) {
    string tmp;
    S[i].push_back('.');
    cin >> tmp;
    S[i] += tmp;
    S[i].push_back('.');
  }
  bool ans = true;
  for(int i = 1; i <= H; i++) {
    for(int j = 1; j <= W; j++) {
      if(S[i][j] == '#' && S[i - 1][j] == '.' && S[i + 1][j] == '.' &&
         S[i][j - 1] == '.' && S[i][j + 1] == '.') {
        ans = false;
      }
    }
  }
  if(ans) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
