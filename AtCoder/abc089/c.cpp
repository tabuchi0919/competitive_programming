#include <algorithm>
#include <deque>
#include <iomanip>
#include <iostream>
#include <iterator>
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
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  map<char, int> mp;
  REP(i, N) {
    string s;
    cin >> s;
    mp[s[0]]++;
  }
  vector<int> nums = {0, 0, 1, 1, 1};
  vector<char> ch = {'M', 'A', 'R', 'C', 'H'};
  ll ans = 0;
  do {
    ll tmp = 1;
    for(int i = 0; i < 5; i++) {
      if(nums[i])
        tmp *= mp[ch[i]];
    }
    ans += tmp;
  } while(std::next_permutation(nums.begin(), nums.end()));
  cout << ans << endl;
}
