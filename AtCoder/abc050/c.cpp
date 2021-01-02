#include <algorithm>
#include <iostream>
#include <math.h>
#include <set>
#include <string.h>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  vector<int> B(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    if(N % 2 == 0) {
      B[i] = i / 2 * 2 + 1;
    } else {
      B[i] = (i + 1) / 2 * 2;
    }
  }
  sort(A.begin(), A.end());
  if(A == B) {
    long long int ans = 1;
    for(int i = 0; i < N / 2; i++) {
      ans *= 2;
      ans %= 1000000007;
    }
    cout << ans << endl;
  } else {
    cout << 0 << endl;
  }
}
