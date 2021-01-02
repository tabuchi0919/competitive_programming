#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <set>
#include <string.h>
#include <vector>

using namespace std;

long long f(long long n) {
  if(n == -1)
    return 0LL;
  if(n % 4 == 0)
    return n;
  if(n % 4 == 2)
    return n ^ 1LL;
  if(n % 4 == 1)
    return 1LL;
  if(n % 4 == 3)
    return 0LL;
}

int main() {
  long long A, B;
  cin >> A >> B;
  cout << (f(A - 1LL) ^ f(B)) << endl;
}
