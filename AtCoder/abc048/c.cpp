#include <algorithm>
#include <iostream>
#include <math.h>
#include <set>
#include <string.h>
#include <vector>
using namespace std;

int main() {
  long long int N, x, ans = 0;
  cin >> N >> x;
  vector<long long int> A(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    if(i == 0) {
      if(A[i] > x) {
        ans += A[i] - x;
        A[i] = x;
      }
    }
    if(i != 0) {
      if(A[i] + A[i - 1] > x) {
        ans += A[i] + A[i - 1] - x;
        A[i] = x - A[i - 1];
      }
    }
  }
  cout << ans << endl;
}
