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
  int n;
  cin >> n;
  if((n - n % 10) % 1110 == 0 || (n - n / 1000) % 111 == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
