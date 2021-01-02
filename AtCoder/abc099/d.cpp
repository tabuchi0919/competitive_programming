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
  int N, C;
  cin >> N >> C;
  vector<vector<int>> D(C, vector<int>(C, 0)), c(N, vector<int>(N, 0));
  for(int i = 0; i < C; i++) {
    for(int j = 0; j < C; j++) {
      cin >> D[i][j];
    }
  }

  vector<vector<int>> count(3, vector<int>(C, 0));
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      int tmp;
      cin >> tmp;
      tmp--;
      c[i][j] = tmp;
      count[(i + j) % 3][c[i][j]]++;
    }
  }
  int ans = INF;
  for(int i = 0; i < C; i++) {
    for(int j = 0; j < C; j++) {
      for(int k = 0; k < C; k++) {
        if(i == j || j == k || k == i)
          continue;
        int tmp = 0;
        for(int l = 0; l < C; l++) {
          tmp += D[l][i] * count[0][l];
          tmp += D[l][j] * count[1][l];
          tmp += D[l][k] * count[2][l];
        }
        ans = min(tmp, ans);
      }
    }
  }
  cout << ans << endl;
}
