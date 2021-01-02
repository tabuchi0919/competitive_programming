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
  int N, T, t, tmp;
  vector<int> c;
  cin >> N >> T;
  for(int i = 0; i < N; i++) {
    cin >> tmp >> t;
    if(t <= T)
      c.push_back(tmp);
  }
  if(c.size() > 0) {
    sort(c.begin(), c.end());
    cout << c[0] << endl;
  } else {
    cout << "TLE" << endl;
  }
}
