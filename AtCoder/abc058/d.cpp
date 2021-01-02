#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <set>
#include <string.h>
#include <vector>
using namespace std;

int main() {
  long long n, m;
  cin >> n >> m;
  long long ansx = 0LL, ansy = 0LL;
  for(long long i = 1LL; i <= n; i++) {
    long long x;
    cin >> x;
    ansx += (((i - 1LL) - (n - i)) * x) % 1000000007;
    ansx %= 1000000007;
  }
  for(long long i = 1LL; i <= m; i++) {
    long long y;
    cin >> y;
    ansy += (((i - 1LL) - (m - i)) * y) % 1000000007;
    ansy %= 1000000007;
  }
  cout << (ansx * ansy) % 1000000007 << endl;
}
