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

const int MOD = 1000000007;
typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, K;
  cin >> N >> K;
  vector<int> V(N);
  for(int i = 0; i < N; i++) {
    cin >> V[i];
  }
  int ans = 0;
  for(int k = 0; k <= min(K, N); k++) {
    for(int i = 0; i <= k; i++) {
      //取る操作をk回行う

      //手持ちの宝石
      vector<int> hand;

      //左からi個handに加える
      for(int left = 0; left < i; left++) {
        hand.push_back(V[left]);
      }

      //右からk-i個handに加える
      for(int right = 0; right < k - i; right++) {
        hand.push_back(V[N - 1 - right]);
      }

      //捨てれる最大回数
      int max_count = K - k;

      int tmp = 0;
      sort(hand.begin(), hand.end());

      for(int j = 0; j < hand.size(); j++) {
        if(hand[j] < 0 && j < max_count) {
          true;
        } else {
          tmp += hand[j];
        }
      }
      ans = max(ans, tmp);
    }
  }
  cout << ans << endl;
}
