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
  int N;
  string S;
  cin >> N >> S;
  vector<int> left(N), right(N);
  left[0] = 0;
  right[N - 1] = 0;
  for(int i = 1; i < N; i++) {
    left[i] = left[i - 1] + (S[i - 1] == 'W');
  }
  for(int i = N - 2; i >= 0; i--) {
    right[i] = right[i + 1] + (S[i + 1] == 'E');
  }
  int ans = INF;
  for(int i = 0; i < N; i++) {
    // cout<<i<<" "<<left[i]<<" "<<right[i]<<endl;
    ans = min(ans, left[i] + right[i]);
  }
  cout << ans << endl;
}
