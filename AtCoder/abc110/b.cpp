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
  vector<int> x(N + 1), y(M + 1);
  cin >> x[0] >> y[0];
  for(int i = 1; i <= N; i++) {
    cin >> x[i];
  }
  for(int i = 1; i <= M; i++) {
    cin >> y[i];
  }

  sort(x.rbegin(), x.rend());
  sort(y.begin(), y.end());

  if(x[0] < y[0]) {
    cout << "No War" << endl;
  } else {
    cout << "War" << endl;
  }
}
