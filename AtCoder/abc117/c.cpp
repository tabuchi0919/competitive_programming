#include <algorithm>
#include <iostream>
#include <math.h>
#include <numeric>
#include <set>
#include <string.h>
#include <vector>
using namespace std;

int main() {
  long long int N, M, ans = 0;
  cin >> N >> M;
  vector<long long int> X(M), Y(M - 1);
  for(int i = 0; i < M; i++) {
    cin >> X[i];
  }
  sort(X.begin(), X.end());
  for(int i = 0; i < M - 1; i++) {
    Y[i] = X[i + 1] - X[i];
  }
  sort(Y.begin(), Y.end());
  for(int i = 0; i < M - N; i++) {
    ans += Y[i];
  }
  cout << ans << endl;
}
