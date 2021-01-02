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
  vector<int> A(N), B(N, 0), C;
  REP(i, N) cin >> A[i];
  for(int i = N; i > 0; i--) {
    int sum = 0;
    for(int j = i; j <= N; j += i) {
      sum += B[j - 1];
    }
    if(A[i - 1] % 2 != sum % 2) {
      B[i - 1] = 1;
    }
  }
  C.reserve(N);
  int M = 0;
  for(int i = 0; i < N; i++) {
    if(B[i] == 1) {
      C.push_back(i + 1);
      M++;
    }
  }
  cout << M << endl;
  if(M != 0) {
    for(int i = 0; i < M - 1; i++) {
      cout << C[i] << ' ';
    }
    cout << C[M - 1] << endl;
  }
}
