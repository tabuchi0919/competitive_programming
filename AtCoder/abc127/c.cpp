#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <random>
#include <set>
#include <string.h>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  ll N, M, mi = 0, ma = 100000000;
  cin >> N >> M;
  vector<ll> L(M), R(M);
  for(int i = 0; i < M; i++) {
    cin >> L[i] >> R[i];
    mi = max(L[i], mi);
    ma = min(R[i], ma);
  }
  cout << max(0ll, ma - mi + 1) << endl;
}
