#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <set>
#include <string.h>
#include <vector>
using namespace std;

long long C[51][51];
void comb_table(int N) {
  for(int i = 0; i <= N; ++i) {
    for(int j = 0; j <= i; ++j) {
      if(j == 0 or j == i) {
        C[i][j] = 1LL;
      } else {
        C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]);
      }
    }
  }
}

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  cout.precision(20);
  comb_table(N);
  vector<long long> v(N);
  for(int i = 0; i < N; i++) {
    cin >> v[i];
  }
  sort(v.rbegin(), v.rend());
  long long sum = accumulate(v.begin(), next(v.begin(), A), 0LL);
  cout << fixed << (double)sum / A << endl;

  long long ans = 0LL;
  long long tmp = v[A - 1];
  int left = distance(v.begin(), find(v.begin(), v.end(), tmp));
  sort(v.begin(), v.end());
  int right = N - distance(v.begin(), find(v.begin(), v.end(), tmp)) - 1;
  sort(v.rbegin(), v.rend());
  if(v[0] != v[A - 1]) {
    ans = C[right - left + 1][A - left];
  } else {
    for(int i = A; i <= B; i++) {
      ans += C[right + 1][i];
    }
  }
  if(ans == 0)
    ans++;
  cout << ans << endl;
}
