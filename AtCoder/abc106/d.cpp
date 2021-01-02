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
  int N, M, Q;
  cin >> N >> M >> Q;
  vector<vector<int>> sum(N + 1, vector<int>(N + 1, 0));
  for(int i = 0; i < M; i++) {
    int L, R;
    cin >> L >> R;
    sum[L][R]++;
  }
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      sum[i + 1][j + 1] += sum[i + 1][j];
    }
  }
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      sum[i + 1][j + 1] += sum[i][j + 1];
    }
  }
  for(int i = 0; i < Q; i++) {
    int L, R;
    cin >> L >> R;
    cout << sum[R][R] + sum[L - 1][L - 1] - sum[L - 1][R] - sum[R][L - 1]
         << endl;
  }
}
