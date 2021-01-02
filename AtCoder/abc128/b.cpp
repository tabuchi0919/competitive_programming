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

bool sortbysec(const tuple<string, int, int> &a,
               const tuple<string, int, int> &b) {
  return (get<1>(a) < get<1>(b));
}

bool sortbyfirst(const tuple<string, int, int> &a,
                 const tuple<string, int, int> &b) {
  return (get<0>(a) < get<0>(b));
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<tuple<string, int, int>> SP(N);
  for(int i = 0; i < N; i++) {
    string s;
    int p;
    cin >> s >> p;
    SP[i] = make_tuple(s, p, i + 1);
  }
  stable_sort(SP.rbegin(), SP.rend(), sortbysec);
  stable_sort(SP.begin(), SP.end(), sortbyfirst);
  for(int i = 0; i < N; i++) {
    cout << get<2>(SP[i]) << endl;
  }
}
