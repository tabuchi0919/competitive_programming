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
  string S;
  int K, N;
  cin >> S >> K;
  N = S.length();
  vector<string> SS;
  SS.reserve(30000);

  for(int i = 0; i < N; i++) {
    SS.push_back(S.substr(i, 1));
  }
  for(int i = 0; i < N - 1; i++) {
    SS.push_back(S.substr(i, 2));
  }
  for(int i = 0; i < N - 2; i++) {
    SS.push_back(S.substr(i, 3));
  }
  for(int i = 0; i < N - 3; i++) {
    SS.push_back(S.substr(i, 4));
  }
  for(int i = 0; i < N - 4; i++) {
    SS.push_back(S.substr(i, 5));
  }
  sort(ALL(SS));
  SS.erase(unique(SS.begin(), SS.end()), SS.end());
  cout << SS[K - 1] << endl;
}
