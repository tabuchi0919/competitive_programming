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
  int n;
  cin >> n;
  vector<ll> L(100);
  L[0] = 2;
  L[1] = 1;
  for(int i = 2; i < 100; i++) {
    L[i] = L[i - 2] + L[i - 1];
  }
  cout << L[n] << endl;
}
