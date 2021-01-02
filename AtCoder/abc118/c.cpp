#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <set>
#include <string.h>
#include <vector>
using namespace std;

int gcd(int a, int b) {
  if(a % b == 0) {
    return (b);
  } else {
    return (gcd(b, a % b));
  }
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  int ans = A[0];
  for(int i = 1; i < N; i++) {
    ans = gcd(ans, A[i]);
  }
  cout << ans << endl;
}
