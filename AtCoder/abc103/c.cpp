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

int main() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for(int i = 0; i < n; i++)
    cin >> a[i];

  cout << accumulate(a.begin(), a.end(), 0ll) - n << endl;
}
