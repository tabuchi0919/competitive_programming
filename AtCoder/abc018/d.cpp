#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
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
  int N, M, P, Q, R;
  cin >> N >> M >> P >> Q >> R;
  vector<int> x(R), y(R), z(R);
  for(int i = 0; i < R; i++) {
    cin >> x[i] >> y[i] >> z[i];
    x[i]--;
    y[i]--;
  }

  vector<int> nums(N, 0);
  for(int i = 0; i < P; i++) {
    nums[i] = 1;
  }
  sort(nums.begin(), nums.end());

  int ans = 0;
  do {
    vector<int> man_point(M, 0);
    for(int j = 0; j < R; j++) {
      if(nums[x[j]] == 1) {
        man_point[y[j]] += z[j];
      }
    }
    int tmp = 0;
    sort(man_point.rbegin(), man_point.rend());
    for(int i = 0; i < Q; i++) {
      tmp += man_point[i];
    }
    ans = max(ans, tmp);
  } while(std::next_permutation(nums.begin(), nums.end()));

  cout << ans << endl;
}
