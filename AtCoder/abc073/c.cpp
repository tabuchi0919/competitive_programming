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
  int N, ans = 0;
  map<int, int> A;
  cin >> N;
  for(int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    A[tmp]++;
  }
  for(auto itr = A.begin(); itr != A.end(); ++itr) {
    if(itr->second % 2 == 1) {
      ans++;
    }
  }
  cout << ans << endl;
}
