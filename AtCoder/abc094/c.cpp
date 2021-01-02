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
  vector<int> X(N);
  for(int i = 0; i < N; i++)
    cin >> X[i];
  vector<int> Y = X;
  sort(ALL(X));
  for(int i = 0; i < N; i++) {
    if(Y[i] <= X[N / 2 - 1])
      cout << X[N / 2] << endl;
    else
      cout << X[N / 2 - 1] << endl;
  }
}
