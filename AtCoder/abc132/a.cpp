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
#define ALL(a) (a).begin(), (a).end()
#define rALL(a) (a).rbegin(), (a).rend()

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  map<char, int> mp;
  cin >> s;
  for(int i = 0; i < 4; i++) {
    mp[s[i]]++;
  }
  bool flag = true;
  for(auto e : mp) {
    if(e.second != 2)
      flag = false;
  }
  if(flag) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
