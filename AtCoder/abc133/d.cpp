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
  cin >> N;
  vector<ll> A(N, 0ll), B(N, 0ll);
  for(int i = 0; i < N; i++)
    cin >> A[i];

  B[0] = 0ll;
  for(int i = 1; i < N; i++) {
    B[i] = 2 * A[i - 1] - B[i - 1];
  }
  ll diff = B[0] / 2 + B[N - 1] / 2 - A[N - 1];

  for(int i = 0; i < N; i++) {
    if(i % 2) {
      cout << B[i] + diff << " ";
    } else {
      cout << B[i] - diff << " ";
    }
  }
  cout << endl;
}
