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
  int N, D, ans = 0;
  cin >> N >> D;
  vector<vector<int>> x(N, vector<int>(D));
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < D; j++) {
      cin >> x[i][j];
    }
  }
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < i; j++) {
      int d2 = 0;
      for(int k = 0; k < D; k++) {
        d2 += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
      }
      for(int k = 0; k < 5000; k++) {
        if(k * k == d2)
          ans++;
      }
    }
  }
  cout << ans << endl;
}
