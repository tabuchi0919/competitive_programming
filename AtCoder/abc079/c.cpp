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
  cin.tie(0);
  ios::sync_with_stdio(false);
  string S;
  cin >> S;
  int a, b, c, d;
  a = S[0] - 48;
  b = S[1] - 48;
  c = S[2] - 48;
  d = S[3] - 48;

  if(a + b + c + d == 7) {
    cout << a << '+' << b << '+' << c << '+' << d << "=7" << endl;
  } else if(a + b + c - d == 7) {
    cout << a << '+' << b << '+' << c << '-' << d << "=7" << endl;
  } else if(a + b - c + d == 7) {
    cout << a << '+' << b << '-' << c << '+' << d << "=7" << endl;
  } else if(a - b + c + d == 7) {
    cout << a << '-' << b << '+' << c << '+' << d << "=7" << endl;
  } else if(a + b - c - d == 7) {
    cout << a << '+' << b << '-' << c << '-' << d << "=7" << endl;
  } else if(a - b + c - d == 7) {
    cout << a << '-' << b << '+' << c << '-' << d << "=7" << endl;
  } else if(a - b - c + d == 7) {
    cout << a << '-' << b << '-' << c << '+' << d << "=7" << endl;
  } else if(a - b - c - d == 7) {
    cout << a << '-' << b << '-' << c << '-' << d << "=7" << endl;
  }
}
