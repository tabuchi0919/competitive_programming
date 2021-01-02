#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <set>
#include <string.h>
#include <vector>
using namespace std;

long long gcd(long long a, long long b) {
  if(a % b == 0) {
    return (b);
  } else {
    return (gcd(b, a % b));
  }
}

int main() {
  int N;
  cin >> N;
  long long ans = 1LL;
  for(int i = 0; i < N; i++) {
    long long t;
    cin >> t;
    ans = ans / gcd(ans, t) * t;
  }
  cout << ans << endl;
}
