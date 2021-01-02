#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <set>
#include <string.h>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
  ll r, D, x;
  cin >> r >> D >> x;
  for(int i = 1; i <= 10; i++) {
    x = x * r - D;
    cout << x << endl;
  }
}
