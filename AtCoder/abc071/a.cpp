#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <string.h>
#include <tuple>
#include <vector>

using namespace std;

const int MOD = 1000000007;
typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int x, a, b;
  cin >> x >> a >> b;
  if(abs(x - a) < abs(x - b)) {
    cout << "A" << endl;
  } else {
    cout << "B" << endl;
  }
}
