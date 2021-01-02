#include <algorithm>
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

const int MOD = 1000000007;
typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  vector<int> P(M);
  vector<vector<int>> S(M, vector<int>(N, 0));
  for(int i = 0; i < M; i++) {
    int k;
    cin >> k;
    for(int j = 0; j < k; j++) {
      int s;
      cin >> s;
      s--;
      S[i][s] = 1;
    }
  }
  for(int i = 0; i < M; i++) {
    cin >> P[i];
  }
  int ans = 0;

  for(int bit = 0; bit < (1 << N); bit++) {
    vector<int> now(M, 0);
    for(int i = 0; i < N; i++) {
      if(bit & (1 << i)) {
        for(int j = 0; j < M; j++) {
          if(S[j][i] == 1)
            now[j]++;
        }
      }
    }
    bool flag = true;
    for(int j = 0; j < M; j++) {
      if(now[j] % 2 != P[j])
        flag = false;
    }
    ans += flag;
  }
  cout << ans << endl;
}
