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

typedef long long ll;
const ll MOD = 1000000007;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll K, N = 50;
  cin >> K;
  vector<ll> a(N);
  for(int i = 0; i < N; i++) {
    a[i] = i;
  }
  for(int i = 0; i < N; i++) {
    a[i] += K / N;
  }
  for(int i = 0; i < K % N; i++) {
    a[i] += N + 1;
    for(int j = 0; j < N; j++) {
      a[j]--;
    }
  }

  cout << N << endl;
  for(int i = 0; i < N - 1; i++) {
    cout << a[i] << ' ';
  }
  cout << a[N - 1] << endl;
}
