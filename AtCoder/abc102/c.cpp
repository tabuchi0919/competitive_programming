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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i = 0; i < N; i++) {
    int a;
    cin >> a;
    A[i] = a - i - 1;
  }
  sort(A.begin(), A.end());
  int mid = A[N / 2];
  ll ans = 0ll;
  for(int i = 0; i < N; i++) {
    ans += abs(A[i] - mid);
  }
  cout << ans << endl;
}
