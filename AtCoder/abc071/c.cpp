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
  ll N, ans1 = 0ll, l1 = 0ll, l2 = 0ll;
  cin >> N;
  vector<ll> A(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(A.rbegin(), A.rend());

  for(int i = 0; i < N - 3; i++) {
    if(A[i] == A[i + 1] && A[i] == A[i + 2] && A[i] == A[i + 3]) {
      ans1 = A[i] * A[i];
      break;
    }
  }

  for(int i = 0; i < N - 1; i++) {
    if(A[i] == A[i + 1]) {
      if(l1 == 0) {
        l1 = A[i];
      } else {
        if(A[i] != l1)
          l2 = A[i];
      }
    }
    if(l2 != 0)
      break;
  }
  cout << max(ans1, l1 * l2) << endl;
}
