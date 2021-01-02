#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <random>
#include <set>
#include <string.h>
#include <vector>

using namespace std;

const int MOD = 1000000007;
typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  vector<int> P(M), Y(M);
  vector<vector<int>> data(N + 1);
  for(int i = 0; i < M; i++) {
    cin >> P[i] >> Y[i];
    data[P[i]].push_back(Y[i]);
  }
  for(int i = 0; i < N + 1; i++) {
    sort(data[i].begin(), data[i].end());
  }

  for(int i = 0; i < M; i++) {
    vector<int> &d = data[P[i]];
    int k = lower_bound(d.begin(), d.end(), Y[i]) - d.begin();
    printf("%06d%06d\n", P[i], k + 1);
  }
}
