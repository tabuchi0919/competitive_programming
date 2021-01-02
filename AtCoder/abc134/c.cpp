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
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll N;
  cin >> N;
  vector<int> A(N);
  REP(i, N) cin >> A[i];
  vector<int> B = A;
  sort(ALL(B));
  if(B[N - 1] == B[N - 2]) {
    for(int i = 0; i < N; i++) {
      cout << B[N - 1] << "\n";
    }
  } else {
    for(int i = 0; i < N; i++) {
      if(A[i] == B[N - 1]) {
        cout << B[N - 2] << "\n";
      } else {
        cout << B[N - 1] << "\n";
      }
    }
  }
}
