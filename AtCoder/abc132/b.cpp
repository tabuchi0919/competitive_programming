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
  int N, ans = 0;
  cin >> N;
  vector<int> p(N);
  for(int i = 0; i < N; i++)
    cin >> p[i];
  for(int i = 1; i < N - 1; i++) {
    if((p[i - 1] < p[i] && p[i] < p[i + 1]) ||
       (p[i - 1] > p[i] && p[i] > p[i + 1]))
      ans++;
  }
  cout << ans << endl;
}
