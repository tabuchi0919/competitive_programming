#include <algorithm>
#include <deque>
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
typedef long long ll;

const int INF = (1 << 30) - 1;
const ll INFLL = (1LL << 61) - 1;
const int MOD = 1000000007;

int digit_sum(int num) {
  int sum = 0, dig;
  while(num) {
    dig = num % 10;
    sum = sum + dig;
    num = num / 10;
  }
  return sum;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int a, b;
  cin >> a >> b;
  cout << max(digit_sum(a), digit_sum(b)) << endl;
}
